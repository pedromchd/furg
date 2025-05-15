package main

import (
	"fmt"
)

func fahrenheitToCelsius(f float64) float64 {
	return (f - 32) * 5 / 9
}

func main() {
	var temp float64
	fmt.Print("Digite a temperatura em Fahrenheit: ")
	fmt.Scan(&temp)

	celsius := fahrenheitToCelsius(temp)
	fmt.Printf("%.1f°F -> %.1f°C\n", temp, celsius)
}
