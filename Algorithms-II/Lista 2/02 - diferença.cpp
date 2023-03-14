/*
Exercício 2:
Criar um programa para calcular o tempo entre dois horários quaisquer de um determinado dia.
O programa deve ler dois horários, compostos por três números inteiros, representando horas, minutos e segundos. 
O programa deve verificar se o horário é válido(horas entre 0 e 23, minutos entre 0 e 59, e segundos entre 00 e 59).
O programa deve ter uma função para calcular a quantidade de segundos em um horário, 
e outra função para calcular e imprimir a quantidade de horas, minutos e segundos em uma quantidade de segundos;
*/

#include <stdio.h>

int main()
{
    int hora1, minuto1, segundo1, hora2, minuto2, segundo2, segundos1, segundos2, diferenca;
    
    printf("Digite o primeiro horario (hh mm ss): ");
    scanf("%d %d %d", &hora1, &minuto1, &segundo1);
    printf("Digite o segundo horario (hh mm ss): ");
    scanf("%d %d %d", &hora2, &minuto2, &segundo2);
    
    segundos1 = hora1 * 3600 + minuto1 * 60 + segundo1;
    segundos2 = hora2 * 3600 + minuto2 * 60 + segundo2;
    
    diferenca = segundos2 - segundos1;

    int horas = diferenca / 3600;
    int minutos = (diferenca % 3600) / 60;
    int segundos = diferenca % 60;
    
    printf("A diferenca entre os dois horarios e de %d horas, %d minutos e %d segundos", horas, minutos, segundos);
    return 0;
}
