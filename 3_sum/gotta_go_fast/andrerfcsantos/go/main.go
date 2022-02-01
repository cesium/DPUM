package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Tuple struct {
	A, B, C int
}

func main() {
	var ns []int

	s := bufio.NewScanner(os.Stdin)
	s.Scan()

	stringNumbers := strings.Split(strings.TrimLeft(s.Text(), "\r\n"), " ")
	for _, stringNumber := range stringNumbers {
		n, _ := strconv.Atoi(stringNumber)
		ns = append(ns, n)
	}

	sort.Slice(ns, func(i, j int) bool { return ns[i] < ns[j] })

	var start, end int
	var a, b, c int

	n := len(ns)
	seen := make(map[Tuple]bool)
	for i := 0; i < n-1; i++ {
		a = ns[i]
		start, end = i+1, n-1

		for start < end {

			b, c = ns[start], ns[end]
			s := a + b + c

			switch {
			case s == 0:
				t := Tuple{a, b, c}
				if _, wasSeen := seen[t]; !wasSeen {
					fmt.Printf("%d %d %d\n", a, b, c)
					seen[t] = true
				}

				start++
				end--
			case s > 0:
				end--
			default:
				start++
			}
		}
	}

}
