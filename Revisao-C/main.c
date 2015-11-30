#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
	int matricula;
	float notas[2];
}Aluno;

int avaliarMedia (Aluno a);
void swapVet (int v[], int v2[], int tam);
int ehOrdenado (int v[], int tam);
bool adicionaValor(int v[], int elem, int tam);

int avaliarMedia (Aluno a){
	float media = 0;
	int i;
	
	for (i = 0; i < 2; i++){
		media += a.notas[i];
	}
	
	media = media / 2;
	
	if (media >= 7 && media <= 10){
		return 1;
	}else if(media >= 4 && media < 7){
		return 0;
	}else if(media < 4){
		return -1;
	}else{
		printf("Nota inválida\n");
	}
	
}

void swapVet (int v[], int v2[], int tam){
	int i, aux;
	
	for (i = 0; i < tam; i++){
		aux = v[i];
		v[i] = v2[i];
		v2[i] = aux;
	}
}

/*>>> 	Escreva uma fonção em C que verifique se o vator é ordenado (ordem crescente). O protótipo da função é definida a seguir:
		int ehOrdenado (int v[], int tam); */
int ehOrdenado (int v[], int tam){
	int i = 0;
	
	while (i < tam-1){
		if (v[i] > v[i+1]){
			return 0;
		}
		i++;
	}
	
	return 1;
}

/*>>> 	Implemente uma função que adiciona um valor ao vetor e aumenta seu tamanho. Considere que o vetor suporta apenas 20 valores
		Se o usuário tentar inserir mais de 20 vetores, você não deve adicionar o elemento e deve sinalizar o erro retornado false */
bool adicionaValor(int v[], int elem, int tam){
	
	if (tam < 20){
		tam++;

		v[tam-1] = elem;
		return true;
	}
	printf("TamanhoF %d\n",tam);		
	
	return false;
}
		
int main(int argc, char *argv[]) {
	int v[] = {1};
	int tam = 1;
	int elem = 0;
	int result = 0;
	
	while (tam < 20){
		printf("Digite o valor para adicionar: ");
		scanf("%d",&elem);
		
		result = adicionaValor(v,elem,&tam);
		printf("Adicionou? %d\n", result);	
		printf("Tamanho =  %d\n", tam);	
	}
	
	
	
	return 0;
}
