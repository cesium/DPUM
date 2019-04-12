package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for i := 1; i <= n; i++ {
		fmt.Printf("%s%s\n", strings.Repeat(" ", n-i), strings.Repeat("#", i))
	}

}
