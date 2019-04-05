/*	Crie um programa que implemente o jogo �Bingo de Prog II�. Nesse jogo, o jogador deve selecionar a quantidade 
de n�meros que ele gostaria de apostar (entre 1 e 20), e em seguida, informar os n�meros escolhidos 
(valores entre 0 e 100). 
	Ap�s receber a aposta, o computador sorteia 20 n�meros (entre 0 e 100) e compara os n�meros sorteados com os 
n�meros apostados, informando ao apostador a quantidade de acertos e os n�meros que ele acertou. 

	O seu programa dever� implementar as fun��es ler_aposta, sorteia_valores e compara_aposta. 
	
	A fun��o ler_aposta deve receber como par�metro a quantidade de n�meros que ser�o apostados e um vetor
previamente alocado dinamicamente para armazenar a quantidade exata de n�meros apostados.  A fun��o deve pedir 
para o usu�rio digitar os n�meros apostados e armazena-los no vetor, garantindo que somente n�meros dentro do 
intervalo de 0 a 100 sejam digitados. 
	A fun��o deve seguir o seguinte prot�tipo: 
		void ler_aposta(int *aposta, int n); 
		
	A fun��o sorteia_valores deve receber como par�metro a quantidade de n�meros que ser�o sorteados e um vetor 
previamente alocado dinamicamente para armazenar a quantidade exata de n�meros sorteados. A fun��o deve sortear 
aleatoriamente os n�meros (entre 0 e 100) e armazena-los no vetor. 
	A fun��o deve seguir o seguinte prot�tipo: 
		void sorteia_valores(int *sorteio, int n); 
		
	A fun��o compara_aposta deve receber como par�metro o vetor com os n�meros apostados (aposta), o vetor com os 
n�meros sorteados (sorteio), juntamente com os seus respectivos tamanhos (na e ns) e um ponteiro para uma vari�vel 
inteira (qtdacertos), onde deve ser armazenada a quantidade de acertos. A fun��o deve retornar o ponteiro para um 
vetor alocado dinamicamente contendo os n�meros que o apostador acertou. 
	A fun��o deve seguir o seguinte prot�tipo: 
		int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns); 
		
	Em seguida, crie a fun��o principal do programa utilizado as fun��es criadas anteriormente para implementar o 
jogo �Bingo de Prog II�. Lembre-se que os vetores aposta, sorteio e acertos devem ser alocados dinamicamente e a 
mem�ria alocada deve liberada quando ela n�o for mais ser utilizada. Para sortear n�meros aleat�rios utilize a fun��o
rand da biblioteca stdlib.h. 
	A fun��o rand retorna um n�mero aleat�rio em um determinado intervalo. 
		Exemplo: x = rand() % 10; x vai receber um valor entre 0 e 10 
	Para garantir que novos n�meros aleat�rios sejam sorteados em cada execu��o do programa � necess�rio executar a 
fun��o srand antes de sortear os n�meros.

srand(time(NULL)) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n){
	int i = 0;
	int aux;
	printf("\n----------DIGITE NUMEROS ENTRE 0 E 100----------\n");
	while(i<n){
		printf("Numero %d = ", i+1);
		scanf("%d", &aux);
		if(aux>=0 && aux<=100){
			aposta[i]=aux;
			i++;
		}
		else{
			printf("NUMERO INVALIDO!\n\nDigite Novamente: \n");
		}
	}
}

void sorteia_valores(int *sorteio, int n){
	int i;
	for(i=0; i<n; i++){
		sorteio[i] = rand()%100;
	}
}

int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns){
	int *vet;
	int i, j;
	int n=0;
	for(i=0; i<na; i++){
		for(j=0; j<ns; j++){
			if(aposta[i]==sorteio[j]){
				n++;
			}
		}
	}
	vet = (int *)malloc(sizeof(int) * n);
	n=0;
	for(i=0; i<na; i++){
		for(j=0; j<ns; j++){
			if(aposta[i]==sorteio[j]){
				vet[n]=aposta[i];
				n++;
			}
		}
	}
	*qtdacertos = n;
	return vet;
}

void printVet(int *vet, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}
}

int main(){
	
	srand(time(NULL));
	
	int n_aposta, *vet_aposta;
	int n_sorteio, *vet_sorteio;
	int n_acertos, *vet_acertos;
	
	do{
		printf("DIGITE A QUANTIDADE DE NUMEROS PARA APOSTA DE 1 A 20: ");
		scanf("%d", &n_aposta);
		if(n_aposta>0 && n_aposta<=20){
			vet_aposta = (int *)malloc(sizeof(int) * n_aposta);
			ler_aposta(vet_aposta, n_aposta);
		}
		else printf("VALOR DE APOSTAS INVALIDO!\n\n");
	}while(n_aposta<1 || n_aposta>20);
	
	printf("\nDIGITE A QUANTIDADE DE NUMEROS PARA SORTEIO: ");
	scanf("%d", &n_sorteio);
	
	vet_sorteio = (int *)malloc(sizeof(int) * n_sorteio);
	sorteia_valores(vet_sorteio,n_sorteio);
	
	printf("\nAPOSTA\n");
	printVet(vet_aposta, n_aposta);
	printf("\n\nSORTEIO\n");
	printVet(vet_sorteio, n_sorteio);
	printf("\n\nNUMEROS ACERTADOS\n");
	
	vet_acertos = compara_aposta(vet_aposta, vet_sorteio, &n_acertos, n_aposta, n_sorteio);
	printVet(vet_acertos, n_acertos);
	printf("\nQUANTIDADE DE NUMEROS: %d\n", n_acertos);
	
	free(vet_aposta);
	free(vet_sorteio);
	free(vet_acertos);
	
	return 0;
}
