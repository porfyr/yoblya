package main

import (
	"fmt"
)

func main() {
	var i, j int
	j = 1
	for i = -1; i < 3; i++ {
		j += i
		j *= 2
	}
	fmt.Println(j, i)
	fmt.Println("Ніби робе")
}
