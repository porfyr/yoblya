package main

import (
	"fmt"
)

func main() {
	string := "her month"
	if string[0] == 'i' || string[0] == 'h' {
		if true {
			fmt.Println("noway, true is 1")
		}
		fmt.Println(string[0])

		fmt.Println("well works")
	}
}
