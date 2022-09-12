#include<stdio.h>

int main()
{
    int tam, tam_, i;
    printf("Tamanho do quadrado: ");
    scanf("%d", &tam);
    tam_ = tam;
    i = tam;
    while(i){
        printf("*");
        i--;
    }
    printf("\n");
    if(tam > 0 || tam < 20)
    {
        while(tam_){
        switch (tam_)
        {
            case 1:
                i = tam;
                while(i){
                    printf("*");
                    i--;
                }
                printf("\n");
                break;
            default:
                printf("*");
                i = tam-2;
                while(i){
                    printf(" ");
                    i--;
                }
                printf("*\n");
            
        }
        tam_--;
        }
        
    }
}
