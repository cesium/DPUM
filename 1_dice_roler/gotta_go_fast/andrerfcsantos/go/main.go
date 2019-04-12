package main

import (
	"bufio"
	"fmt"
	"log"
	"math/rand"
	"os"
	"runtime/pprof"
	"strconv"
	"strings"
	"time"
)

func main() {
	fp, err := os.Create("cpu.prof")
	if err != nil {
		log.Fatal("could not create CPU profile: ", err)
	}
	defer fp.Close()
	if err := pprof.StartCPUProfile(fp); err != nil {
		log.Fatal("could not start CPU profile: ", err)
	}
	defer pprof.StopCPUProfile()

	start := time.Now()
	f, _ := os.Open("../../../input.txt")
	//scanner := bufio.NewScanner(os.Stdin)
	scanner := bufio.NewScanner(f)

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
	elapsed := time.Since(start)
	fmt.Printf("%v\n", elapsed)
}
