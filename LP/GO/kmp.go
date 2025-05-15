package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func countOccurrences(text, word string) int {
	count := 0
	for i := 0; i <= len(text)-len(word); i++ {
		if text[i:i+len(word)] == word {
			count++
		}
	}
	return count
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Digite o texto: ")
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)

	fmt.Print("Digite a palavra: ")
	word, _ := reader.ReadString('\n')
	word = strings.TrimSpace(word)

	count := countOccurrences(text, word)
	fmt.Printf("Temos que a palavra %s ocorre %d vez(es) na frase.\n", word, count)
}
