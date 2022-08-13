package main

import "fmt"

type citizen struct {
	name    string
	bottles int
}

func main() {

	var Gogi citizen

	getData(&Gogi)
	prData(Gogi)

	fmt.Println("\nmaybe maybe\n")
}

func getData(Gogi *citizen) {
	Gogi.name = "Georgiy"
	Gogi.bottles = 0
}

func prData(Gogi citizen) {
	fmt.Printf("%v, випив %v чернігівського\n", Gogi.name, Gogi.bottles)
}
