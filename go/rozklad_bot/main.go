package main

import (
	"fmt"
	//tgbotapi "github.com/go-telegram-bot-api/telegram-bot-api/v5"
)

type her struct {
	sm int
}

func add(p *her) {
	p.sm++
}

func main() {

	var i *her
	x := her{sm: 3}
	i = &x
	add(i)
	fmt.Println(i.sm)

	fmt.Println("\nробе")
}
