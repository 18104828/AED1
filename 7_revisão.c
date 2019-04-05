/*Crie um programa para manipular vetores. 
O seu programa deve implementar uma fun��o que receba um vetor de inteiros V e retorne um outro vetor de inteiros 
alocado dinamicamente com todos os valores de V que estejam entre o valor m�nimo e m�ximo (que tamb�m s�o passados 
como par�metro para a fun��o). 

A fun��o deve obedecer ao seguinte prot�tipo: int* valores_entre(int *v, int n, int min, int max, int *qtd); 

A fun��o recebe: 
	� v: vetor de n�meros inteiros; 
	� n: a quantidade de elementos do vetor v; 
	� min: valor m�nimo a ser buscado; 
	� max: valor m�ximo a ser buscado; 
	
A fun��o deve: 
	� Verificar a quantidade de elementos do vetor que sejam maiores do que min e menores que max; 
	� Caso a quantidade seja maior do que 0 (zero), alocar dinamicamente uma �rea do exato tamanho necess�rio 
para armazenar os valores; 
	� Copia os elementos do vetor que sejam maiores do que min e menores que max para a �rea alocada dinamicamente. 

A fun��o retorna: 
	� O endere�o da �rea alocada dinamicamente, preenchida com os n�meros maiores do que min e menores que max,
ou NULL, caso essa rela��o de n�meros n�o tenha sido criada; 
	� A quantidade de n�meros carregados na �rea alocada dinamicamente, atrav�s do par�metro qtd. 
	
Em seguida, crie a fun��o principal do programa para inicializar um vetor de inteiros, exibir
esses valores na tela e pedir para o usu�rio digitar o valor m�nimo e m�ximo a ser
buscado. 
Em seguida o programa dever� chamar a fun��o valores_entre e exibir na tela os valores resultantes. 
Lembre-se de exibir uma mensagem de erro caso nenhum valor seja encontrado. 
N�o se esque�a de liberar a mem�ria alocada dinamicamente.*/

#include <stdio.h>
#include <stdlib.h>

int* manipulaVet(int *v, int n, int min, int max, int *qtd){
	int elem = 0, i, j=0;
	int *v2;
	for(i=0; i<n; i++){
		if(v[i]>min && v[i]<max) elem++;
	}
	if(elem>0){
		v2 = (int *)malloc(elem * sizeof(int));
		for(i=0; i<n; i++){
			if(v[i]>min && v[i]<max){
				v2[j] = v[i];
				j++;
			}
		}
		*qtd = elem;
		return v2;
	}
	else{
		*qtd = 0;
		return NULL;
	}
}

int main(){
	
	int n;
	
	printf("Digite a quantidade: ");
	scanf("%d", &n);
	
	int vet[n];
	int *vet2;
	int i;
	int qtd;
	
	printf("----------NUMEROS ALEATORIOS ENTRE 0 E 100----------\n");
	
	for(i=0; i<n; i++){
		vet[i] = rand()%100;
		printf("%d ", vet[i]);
	}
	
	printf("\n");
	int max, min;
	
	printf("\nINFORME OS VALORES DE MAXIMO E MINIMO\n");
	printf("Maximo: ");
	scanf("%d", &max);
	printf("Minimo: ");
	scanf("%d", &min);
	
	vet2 = manipulaVet(vet,n,min,max,&qtd);
	
	printf("\nQUANTIDADE DE NUMEROS: %d\n", qtd);
	
	if(qtd == 0) printf("NAO FOI ENCONTRADO NENHUM NUMERO ENTRE OS VALORES DE MAXIMO E MINIMO");
	
	else{
		printf("----------NUMEROS ENTRE OS VALORES DE MAXIMO E MINIMO----------\n");
		for(i=0; i<qtd; i++){
			printf("%d ", vet2[i]);
		}
	}
	
	free(vet2);
	
	return 0;
}
