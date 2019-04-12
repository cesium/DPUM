package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
)

func main() {
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
}
