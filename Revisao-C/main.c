#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Defina a struct Aluno que possui os seguintes campos:
número de matrícula e um vetor de notas.
Defina a função avaliarMedia que recebe uma struct “Aluno”, calcula a média das duas notas contidas o vetor “notas” e retorna:
1 caso o aluno tenha sido aprovado (média >= 7),
0 caso tenha que fazer AF (7 > média >= 4) e;
-1 caso esteja reprovado (média < 4)
*/

typedef struct{
	int matricula;
	float notas[2];
}Aluno;

int avaliarMedia (Aluno a);
void swapVet (int v[], int v2[], int tam);
int ehOrdenado (int v[], int tam);
bool adicionaValor(int v[], int elem, int *tam);
bool subPos(char menor[], char maior[], int pos);

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
/*
Escreva uma função em C que recebe dois vetores e troca seus
elementos. O protótipo da função é definido a seguir:
void swapVet(int v1[], int v2[], int tam);
*/

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

/*
Implemente uma função que adiciona novos valores no vetor e
aumenta seu tamanho. Considere que o vetor suporta apenas 20
valores. Se o usuário tentar inserir mais de 20 valores, você não
deve adicionar o elemento e deve sinalizar o erro retornando false.
*/
bool adicionaValor(int v[], int elem, int *tam){
	if (*tam < 20){
		*tam = *tam + 1;
		v[*tam - 1] = elem;
		return true;
	}
	return false;
}
/*
Faça uma função que recebe uma substring menor, uma string maior e uma posição e verifica se a substring pode ser encontrada
na posição passada na substring maior. Ex: menor = “bin” maior = “o bin laden e o bingo” se pos = 2 ou 16 voce deve retornar
true, e false, caso contrário. O protótipo dessa função é dado a seguir:
int subPos(char menor[], char maior[], int pos);
*/		

bool subPos(char menor[], char maior[], int pos){
	int i = 0, verdade = 1, tam = strlen(menor);
	
	for(i = 0; i < tam; i++, pos++){
		if(maior[pos] == menor[i]){
			verdade = 1;
			i++;
			pos++;
		}else{
			verdade = 0;
		}	
	}
	
	
	if(verdade == 1){
		return true;
	}else{
		return false;	
	}
}

void testeSubPos(){
	char v1[] = "bin";
	char v2[] = "o bin laden e o bingo";
	int pos = 2; 
	
	printf("Teste da funcao SubPos\n");
	if(subPos(v1,v2,pos) == true){
		printf("	ok!");
	}else{
		printf("	NOT ok");
	}
}
		
int main(int argc, char *argv[]) {
	
	testeSubPos();
	
	return 0;
}
