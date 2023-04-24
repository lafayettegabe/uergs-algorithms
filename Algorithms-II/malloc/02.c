/*
Elabore um programa que armazena as notas de 2 provas e 1 trabalho de um número não fixo de alunos de uma turma 
(a nota 1 tem peso 2, a 2 tem peso 3 e a 3 peso 1), 
posteriormente calcule a média das três notas para cada aluno da turma. 
Depois imprima um relatório que compara a média de cada aluno com a média da turma informando ao lado 
do índice do aluno e sua média se ele está abaixo, acima ou na média da turma.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    float *notas;
    int alunos;

    // Recebe os alunos
    printf("Digite o número de alunos: ");
    scanf("%d", &alunos);

    // Aloca memória para as 3 notas de cada aluno
    notas = (float *) malloc(alunos * (3*sizeof(float)));



}