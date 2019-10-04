package main

import (
	"bufio"
	"fmt"
	"os"
  "sync"
)

var wg sync.WaitGroup

func smosh(line string, m map[string]string) {
  code := ""
  for i := 0; i < len(line); i++ {
    code = code + m[string(line[i])]
  }
  fmt.Println(code)
  wg.Done()
}

func main() {

  m  := map[string]string{
    "a": ".-",
    "b": "-...",
    "c": "-.-.",
    "d": "-..",
    "e": ".",
    "f": "..-.",
    "g": "--.",
    "h": "....",
    "i": "..",
    "j": ".---",
    "k": "-.-",
    "l": ".-..",
    "m": "--",
    "n": "-.",
    "o": "---",
    "p": ".--.",
    "q": "--.-",
    "r": ".-.",
    "s": "...",
    "t": "-",
    "u": "..-",
    "v": "...-",
    "w": ".--",
    "x": "-..-",
    "y": "-.--",
    "z": "--..",
  }

  scanner := bufio.NewScanner(os.Stdin)

  for scanner.Scan() {
    line := scanner.Text()
    wg.Add(1)
    go smosh(line, m)
  }
  wg.Wait()
}
