package main

import (
	"fmt"
)

func main() {
	fmt.Println(TwoOldestAges([]int{1, 4, 9, 6, 3}))
}

func TwoOldestAges(ages []int) [2]int {
	res := [2]int{}
	temp := -10000000
	ext_ix := 0
	for idx, el := range ages {
		if el > temp {
			temp = el
			ext_ix = idx
		}
	}
	res[1] = temp
	temp = -10000000

	for idx, el := range ages {
		if el > temp && idx != ext_ix {
			temp = el
		}
	}
	res[0] = temp
	return res
}
