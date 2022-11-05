//usr/bin/go run "$0" "$@" ; exit "$?"
package main

import (
	"fmt"
	"os"
)

func main() {
	s := "hehe"
	if len(os.Args) > 1 {
		s = os.Args[1]
	}
	fmt.Printf("Hello, %v\n", s)
	if s == "fail" {
		os.Exit(30)
	}
}
