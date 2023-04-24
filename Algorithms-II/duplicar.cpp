#include<stdio.h>
#include<string.h>

// duplicate

int main() {
	char palavra[50];
	int i=0,j=0, tamanho=0;
	
	gets(palavra);
	
    while(palavra[i] != '\0') {
		if ( palavra[i++] == ' ') {
			
			for(int k = i; k < 50; k++) {
				if( k + tamanho < 50)
					palavra[k+tamanho] = palavra[k];
			}
			
			while(j < i) {
				palavra[i++] = palavra[j++];
			}
			tamanho = 0;
		}
		tamanho++;
		i++;
	}
	
	puts(palavra);
}

