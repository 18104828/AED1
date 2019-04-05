/* Fa�a uma fun��o que receba um valor n e crie dinamicamente um vetor de n
elementos e retorne um ponteiro. Crie uma fun��o que receba um ponteiro para um
vetor e um valor n e imprima os n elementos desse vetor. Construa tamb�m uma
fun��o que receba um ponteiro para um vetor e libere esta �rea de mem�ria. Ao final,
crie uma fun��o principal que leia um valor n e chame a fun��o criada acima. Depois, a
fun��o principal deve ler os n elementos desse vetor. Ent�o, a fun��o principal deve
chamar a fun��o de impress�o dos n elementos do vetor criado e, finalmente, liberar a
mem�ria alocada atrav�s da fun��o criada para libera��o. */

#include <stdio.h>
#include <stdlib.h>

int* vetDinamic(int tam){
	int *p;
	p = (int *)malloc(sizeof(int)*tam);
	return p;
}

void printVet(int tam, int *p){
	int i;
	for(i=0; i<tam; i++){
		printf("%d\n", p[i]);
	}
}

void freeVet(int *p){
	free(p);
}

void funPrinc(int n){
	int *p;
	
	printf("Valor= ");
	scanf("%d", &n);
	
	p = vetDinamic(n);
	
	int i;
	for(i=0; i<n; i++){
		p[i] = i+1;
	}
	
	printVet(n,p);
	freeVet(p);
}

int main(){
	
	int n;
	
	funPrinc(n);
	
	return 0;
}
