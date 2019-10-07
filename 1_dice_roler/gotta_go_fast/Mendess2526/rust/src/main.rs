extern crate memmap;
extern crate rand;

use memmap::MmapOptions;
use rand::Rng;
use std::fmt::Write as WriteFmt;
use std::fs::File;
use std::io::{IoSlice, Write};
use std::thread;

fn do_it(line: &[u8], out: &mut String) {
    if line.is_empty() {
        return;
    }
    let mut rolls: u64 = 0;
    let mut faces: u64 = 0;
    let mut pre_d = true;
    for c in line {
        if *c == b'd' {
            pre_d = !pre_d;
            continue;
        }
        if pre_d {
            rolls = (rolls * 10) + u64::from(*c - b'0');
        } else {
            faces = (faces * 10) + u64::from(*c - b'0');
        }
    }
    let mut sum: u64 = 0;
    let mut rng = rand::thread_rng();
    for _i in 0..rolls {
        sum += 1 + rng.gen::<u64>() % faces;
    }
    let _ = writeln!(out, "{}", sum);
}

fn main() -> std::io::Result<()> {
    let file = File::open(
        std::env::args_os()
            .nth(1)
            .unwrap_or_else(|| "input.txt".into()),
    )?;
    let memmap = unsafe { MmapOptions::new().map(&file)? };

    let chunk_size = memmap.len() / num_cpus::get();
    let mut threads = Vec::with_capacity(num_cpus::get());
    let mut index: usize = chunk_size;
    let mut last_index: usize = 0;
    while index < memmap.len() {
        while memmap[index] != b'\n' {
            index += 1;
        }
        let slice: &'static [u8] = unsafe { &*(&memmap[last_index..index] as *const _) };
        threads.push(thread::spawn(move || {
            let mut out = String::with_capacity(slice.len());
            slice
                .split(|c| *c == b'\n')
                .for_each(|line| do_it(line, &mut out));
            out
        }));
        last_index = index;
        index += chunk_size;
    }
    let mut out = String::with_capacity(memmap[last_index..].len());
    memmap[last_index..]
        .split(|c| *c == b'\n')
        .for_each(|line| do_it(line, &mut out));
    let r = threads
        .into_iter()
        .map(|t| Vec::from(t.join().unwrap()).into_boxed_slice())
        .chain(std::iter::once(Vec::from(out).into_boxed_slice()))
        .collect::<Vec<Box<[u8]>>>();
    let slices = r.iter().map(|s| IoSlice::new(&*s)).collect::<Vec<_>>();
    std::io::stdout().lock().write_vectored(&slices).map(|_| ())
}
