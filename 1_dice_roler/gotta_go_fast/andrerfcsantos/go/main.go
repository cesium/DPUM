package main

import (
	"bufio"
	"flag"
	"fmt"
	"log"
	"math/rand"
	"os"
	"runtime/pprof"
	"runtime/trace"
	"strconv"
	"strings"
)

var tracerEnabled bool
var cpuProfileEnabled bool

func parseFlags() {
	flag.BoolVar(&tracerEnabled, "trace", false, "")
	flag.BoolVar(&cpuProfileEnabled, "cpu", false, "")
	flag.Parse()
}

func main() {
	parseFlags()
	if cpuProfileEnabled {
		fp, err := os.Create("maincpu.prof")
		if err != nil {
			log.Fatal("could not create CPU profile: ", err)
		}
		defer fp.Close()
		if err := pprof.StartCPUProfile(fp); err != nil {
			log.Fatal("could not start CPU profile: ", err)
		}
		defer pprof.StopCPUProfile()

	}

	if tracerEnabled {
		f, err := os.Create("maintrace.out")
		if err != nil {
			log.Fatalf("failed to create trace output file: %v", err)
		}
		defer func() {
			if err := f.Close(); err != nil {
				log.Fatalf("failed to close trace file: %v", err)
			}
		}()

		if err := trace.Start(f); err != nil {
			log.Fatalf("failed to start trace: %v", err)
		}
		defer trace.Stop()
	}

	//f, _ := os.Open("../../../input.txt")
	//scanner := bufio.NewScanner(f)

	scanner := bufio.NewScanner(os.Stdin)

	for scanner.Scan() {
		data := strings.Split(scanner.Text(), "d")
		n, _ := strconv.Atoi(data[0])
		d, _ := strconv.Atoi(data[1])

		var sum int
		for i := 0; i < n; i++ {
			sum += rand.Intn(d-1) + 1
		}
		fmt.Println(d)
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
}
