#include <stdio.h>

// 1) Desenvolver um algoritmo que efetue a soma de todos os números ímpares que são múltiplos de três e que se encontram no conjunto dos números de 1 até 500. 

int main() {
	for(int i = 3; i <= 500; i += 3)
		if(i % 2 != 0) printf("%d ", i);
}
