/*	Crie uma fun��o que receba como par�metros dois vetores de inteiros, v1 e v2, e as suas respectivas 
quantidades de elementos, n1 e n2. 
	A fun��o dever� retornar um ponteiro para um terceiro vetor, v3, com capacidade para (n1 + n2) elementos,
alocado dinamicamente, contendo a uni�o de v1 e v2. 
	Por exemplo, se v1 = {11, 13, 45, 7} 
					v2 = {24, 4, 16, 81, 10, 12}
					v3 ir� conter {11, 13, 45, 7, 24, 4, 16, 81, 10, 12}. 
	O cabe�alho dessa fun��o dever� ser o seguinte: int* uniao(int *v1, int n1, int *v2, int n2); 
	Em seguida, crie a fun��o principal do programa para chamar a fun��o uniao passando dois vetores informados 
pelo usu�rio (ou declarados estaticamente). 
	Em seguida, o programa deve exibir na tela os elementos do vetor resultante. 
	N�o esque�a de liberar a mem�ria alocada dinamicamente. */
	
#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){
	int *v3;
	
	v3 = (int *)malloc(sizeof(int)*(n1+n2));
	
	int i,j;
	
	for(i=0; i<n1; i++){
		v3[i] = v1[i];
	}
	
	for(j=0; j<n2; j++){
		v3[i] = v2[j];
		i++;
	}
	
	return v3;
}

int main(){
	
	int v1[4] = {11, 13, 45, 7}, v2[6] = {24, 4, 16, 81, 10, 12}, *v3;
	
	v3 = uniao(v1,4,v2,6);
	
	int i;
	
	for(i=0; i<10; i++){
		printf("%d ", v3[i]);
	}
	
	free(v3);
	
	return 0;
}
