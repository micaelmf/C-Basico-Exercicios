#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Defina a struct Aluno que possui os seguintes campos:
n�mero de matr�cula e um vetor de notas.
Defina a fun��o avaliarMedia que recebe uma struct �Aluno�, calcula a m�dia das duas notas contidas o vetor �notas� e retorna:
1 caso o aluno tenha sido aprovado (m�dia >= 7),
0 caso tenha que fazer AF (7 > m�dia >= 4) e;
-1 caso esteja reprovado (m�dia < 4)
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
		printf("Nota inv�lida\n");
	}
	
}
/*
Escreva uma fun��o em C que recebe dois vetores e troca seus
elementos. O prot�tipo da fun��o � definido a seguir:
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

/*>>> 	Escreva uma fon��o em C que verifique se o vator � ordenado (ordem crescente). O prot�tipo da fun��o � definida a seguir:
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
Implemente uma fun��o que adiciona novos valores no vetor e
aumenta seu tamanho. Considere que o vetor suporta apenas 20
valores. Se o usu�rio tentar inserir mais de 20 valores, voc� n�o
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
Fa�a uma fun��o que recebe uma substring menor, uma string maior e uma posi��o e verifica se a substring pode ser encontrada
na posi��o passada na substring maior. Ex: menor = �bin� maior = �o bin laden e o bingo� se pos = 2 ou 16 voce deve retornar
true, e false, caso contr�rio. O prot�tipo dessa fun��o � dado a seguir:
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
