#include <stdio.h>
#include <string.h>

int main()
{
   	char palavra[50];
   	int i, count = 1, j = 0;
   	
	gets(palavra);   
    
    while(palavra[i] != '\0') {
    	if ( (int)palavra[i++] == 32) {
    		count++;
		}
	}
	
	printf("Ha %d palavras.", count);
}


