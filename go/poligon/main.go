package main

import (
	"fmt"
	//"os"
)

func main() {

	I := Hk{"sn", 8}

	I.print()
	I.plusYr()
	I.print()

	//fmt.Println("Ніби робе")
}

type Hk struct {
	name string
	age  int8
}

func (u Hk) print() {
	fmt.Printf("%v: %v\n", u.name, u.age)
}

func (u *Hk) plusYr() {
	u.age++
}
