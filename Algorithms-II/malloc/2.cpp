/*
Elabore um programa que armazena as notas de 2 provas e 1 trabalho de um n�mero n�o fixo de alunos de uma turma 
(a nota 1 tem peso 2, a 2 tem peso 3 e a 3 peso 1), 
posteriormente calcule a m�dia das tr�s notas para cada aluno da turma. 
Depois imprima um relat�rio que compara a m�dia de cada aluno com a m�dia da turma informando ao lado 
do �ndice do aluno e sua m�dia se ele est� abaixo, acima ou na m�dia da turma.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    float *notas, mTurma = 0;
    int alunos;

    // Recebe os alunos
    printf("Digite o numero de alunos: ");
    scanf("%d", &alunos);

    // Aloca mem�ria para as 3 notas de cada aluno
    notas = (float *) malloc(alunos * 3 *sizeof(float));

	// Recebe as notas	
	for(int i = 0; i < alunos; i++) {
		
		printf("Aluno %d | Prova 1: ", i);
		scanf("%f", (notas + i * 3 + 0));
	
		printf("Aluno %d | Prova 2: ", i);
		scanf("%f", (notas + i * 3 + 1));
	
		printf("Aluno %d | Trabalho: ", i);
		scanf("%f", (notas + i * 3 + 2));
		
	}
	
	// Mostra as notas e a m�dia
	for(int i = 0; i < alunos; i++) {
		float media = ((*(notas + i * 3 + 0) * 2) + (*(notas + i * 3 + 1) * 3) + *(notas + i * 3 + 2)) / 6;
		mTurma += media;
		printf("\nAluno %d | Prova 1: %.1f | Prova 2: %.1f | Trabalho: %.1f | Media: %.1f | Situacao: ", i, notas[i * 3 + 0], notas[i * 3 + 1], notas[i * 3 + 2], media);
		(media >= 6) ? printf("Aprovado") : printf("Reprovado");
	}
	
	printf("\nMedia da turma: %.1f", mTurma/alunos);
}
