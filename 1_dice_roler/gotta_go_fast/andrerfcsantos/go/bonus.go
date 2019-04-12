package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

func main() {

	start := time.Now()
	f, _ := os.Open("../../../input.txt")
	//scanner := bufio.NewScanner(os.Stdin)
	scanner := bufio.NewScanner(f)

	for scanner.Scan() {
		data := strings.Split(scanner.Text(), "d")
		n, _ := strconv.Atoi(data[0])
		d, _ := strconv.Atoi(data[1])

		var sum int
		var rolls []int
		for i := 0; i < n; i++ {
			roll := rand.Intn(d-1) + 1
			rolls = append(rolls, roll)
			sum += roll
		}
		fmt.Printf("%d:", sum)
		for _, r := range rolls {
			fmt.Printf(" %d", r)
		}
		fmt.Print("\n")
	}
	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "reading standard input:", err)
	}
	elapsed := time.Since(start)
	fmt.Printf("%v\n", elapsed)
}
