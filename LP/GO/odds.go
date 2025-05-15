package main

import (
	"fmt"
)

func writeOdds(n int) {
	for i := 1; i <= n; i++ {
		fmt.Printf("%d ", 2*i+1)
	}
	fmt.Println()
}

func main() {
	var num int
	fmt.Print("Digite o número de ímpares: ")
	fmt.Scan(&num)

	writeOdds(num)
}
