package main

import (
	"fmt"
)

func isPrime(number int) bool {
	if number < 2 {
		return false
	}
	for i := 2; i < number; i++ {
		if number%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var num int
	fmt.Print("Digite um número: ")
	fmt.Scan(&num)

	if isPrime(num) {
		fmt.Printf("%d é primo!\n", num)
	} else {
		fmt.Printf("%d não é primo...\n", num)
	}
}
