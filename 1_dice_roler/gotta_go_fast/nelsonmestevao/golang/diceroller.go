package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
)

func alea_iacta_est(rolls int, faces int) int {
	sum := 0

	for i := 1; i < rolls; i++ {
		sum += rand.Intn(faces + 1)
	}

	return sum
}

func main() {
	file, _ := os.Open(os.Args[1])
	defer file.Close()

	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		s := strings.Split(scanner.Text(), "d")

		rolls, _ := strconv.Atoi(s[0])
		faces, _ := strconv.Atoi(s[1])

		fmt.Println(alea_iacta_est(rolls, faces))
	}
}
