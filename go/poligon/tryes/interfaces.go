package main

import (
	"fmt"
	_ "fmt"
	_ "net/http"
)

type an interface {
	make_s()
}

type cat struct{}
type dog struct{}

func (c *cat) make_s() {
	fmt.Println("мяу")
}

func (c *dog) make_s() {
	fmt.Println("гав")
}

func main() {

	var c, d an = &cat{}, &dog{}
	c.make_s()
	d.make_s()

	//fmt.Println("Робе пхд")
}
