use std::io::Write;
fn main() {
    let size: usize = std::env::args()
        .nth(1)
        .expect("Not enough arguments")
        .parse()
        .expect("Failed to parse");
    let mut buffer = Vec::with_capacity(size + 1);
    buffer.resize(size, b' ');
    buffer.push(b'\n');
    let mut buffer = buffer.into_boxed_slice();
    let sout = std::io::stdout();
    let mut stdout = sout.lock();
    for i in 0..size {
        let i = size - i - 1;
        buffer[i] = b'#';
        let _ = stdout.write_all(&buffer);
    }
    let _ = stdout.flush();
}
