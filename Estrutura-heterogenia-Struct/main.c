/* Lista - Struct */
#include <stdio.h>

/*Q1: Soma */
/* Utilizando a struct abaixo, crie uma função que recebe uma struct “numeros”
  e retorna a soma de a e b. */

typedef struct
{
    int a;
    int b;
}Numeros;

int soma(Numeros n){
	int soma = 0;
	
	soma = n.a + n.b;
	
    return soma;
    //return n.a + n.b;
}

/*Q2: Maior Número */
/*Escreva uma função que recebe uma variável do tipo “numeros” e retorna o maior entre a e b.*/

int maiorNumero(Numeros n){
	
    if (n.a > n.b){
    	return n.a;
	}else{
		return n.b;
	}
	
    return 0;
}

/* Q3:  Maior Elemento */
/* Crie uma função que recebe como argumento uma struct “vetor”, e retorna o maior elemento
  desse vetor.*/
typedef struct
{
    int v[10];
    int tamanho;
}Vetor;

int maiorElemento(Vetor a){
    int i, maior = 0;
    
    for(i = 0; i < a.tamanho; i++){
    	if(a.v[i] > maior){
    		maior = a.v[i];
		}
	}
	
	return maior;
}

/*Q4: Calculadora */
/* Vamos alterar agora a struct “numeros”, ambas as variáveis a e b agora são do
   tipo float e será acrescentado mais uma variável do tipo char chamada “operador”,
   ela deve conter o tipo de operação que será realizada entre a e b.
   Utilizando a nova struct, crie uma função que retorna o resultado da operação
   realizada entre a e b, onde a operação a ser realizada é soma (‘+’), subtração (‘-’),
   divisão (‘/’) ou multiplicação (‘*’), dependendo do tipo de operação armazenada
   na variável “operador” */

typedef struct
{
    float a;
    float b;
    char operador;
}Numeros2;

float calcular(Numeros2 n){
	float result = 0;
	
	if(n.operador = '+'){
		result = n.a + n.b;
	}else if(n.operador == '-'){
		result = n.a - n.b;
	}else if(n.operador == '*'){
		result = n.a * n.b;			
	}else if(n.operador == '/'){
		result = n.a * n.b;
	}else{
		printf("Operador invalido");
	}
	
    return result;
}

/* Q5: Média das Notas */
/* Utilizando a struct “aluno” definida abaixo, crie uma função que calcula e retorna
  a média das três notas contidas no vetor “notas”. */

typedef struct
{
    int matricula;
    float notas[3];
}Aluno;

float media(Aluno a){
	int i, media = 0, soma = 0;
	
	for(i = 0; i < 3; i++){
		soma += a.notas[i];
	}

	media = soma/i;
	
    return media;

}

/* Q6: Maior Média */
/* Com a struct e a função criada na questão anterior, crie uma nova função, que recebe um
  vetor de n alunos como argumento, e retorna o número de matrícula do aluno com maior média. */

int maiorMedia(Aluno a[], int n){
int i = 0, melhor = 0;
		
	for(i = 0; i < 3; i++){
		if (melhor < media(a[i])){
			melhor = media(a[i]);
		}
	}
	
    return melhor;

}


/* Construir Personagem */

/* A struct "personagem" contém os atributos de um personagem em um jogo de RPG, utilizando
  essa struct e a função criarPersonagem constrói um novo personagem. */

typedef struct
{
    int vida;
    int ataque;
}Personagem;

Personagem criarPersonagem(int vida, int ataque){
	Personagem p;
    p.ataque = ataque;
    p.vida = vida;
    return p;
}

/* Q8: Duelo */
/* Agora vamos criar a função "duelo", ela recebe dois personagens e faz os dois duelar.
A função deve retornar 1 se o personagem a ganhar e 0 caso contrário.
Dicas: Utilize um laço while e enquanto os dois personagens estiverem vivos, ou sejá
a vida dos dois for maior que 0, os dois devem continuar se atacando.
Quando o personagem a ataca o b, a quantidade de vida que o personagem b perde
é igual ao ataque de a, a mesma coisa acontece quando b ataca a. */

int duelo(Personagem a, Personagem b){
    	while(a.vida > 0 && b.vida > 0){
		a.vida -= b.ataque;
		b.vida -= a.ataque;
		
	}
	
	if (a.vida > 0 && b.vida <= 0){
		return 1;
	}else{
		return 0;
	}
}

/**Implementação das funções de teste **/

void test_soma()
{
    printf("---------------------\n");
    printf("teste Soma\n");
    Numeros n = {5, 5};
    if(soma(n) == 10){
        printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

void test_maior_numero()
{
    printf("---------------------\n");
    printf("teste Maior Numero.\n");
    Numeros n = {1, 2};
    if(maiorNumero(n) == 2){
        printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

void test_maior_elemento()
{
    printf("---------------------\n");
    printf("teste Maior Elemento.\n");
    Vetor a = {{12, 5, 6, 7, 8}, 5};
    if(maiorElemento(a) == 12){
        printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

void test_calculadora()
{
    printf("---------------------\n");
    printf("teste Calculadora.\n");
    Numeros2 n = {5, 5, '+'};
    if(calcular(n) == 10 && calcular(n) == 0 && calcular(n) == 25 && calcular(n) == 1){
        printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

void test_media_notas()
{
    printf("---------------------\n");
    printf("teste Media das Notas.\n");
    Aluno a = {132, {5, 10, 6}};
    if(media(a) == 7){
        printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

void test_maior_media()
{
    printf("---------------------\n");
    printf("teste Maior Media.\n");
    Aluno a[3];
    a[0] = (Aluno){5, {2,9,5}};
    a[1] = (Aluno){6, {5,9,5}};
    a[2] = (Aluno){7, {3,9,5}};

    if(maiorMedia(a,3) == 6){
        printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

void test_criar_personagem()
{
	printf("---------------------\n");
	printf("teste Criar Personagem.\n");
	Personagem p;
	p = criarPersonagem(100, 20);
	if(p.vida == 100 && p.ataque == 20){
        printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

void test_duelo()
{
	printf("---------------------\n");
	printf("teste Duelo.\n");
	Personagem a = {100, 20};
	Personagem b = {100, 1};
	if(duelo(a, b) == 1 && duelo(b, a) == 0){
	    printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

int main()
{
    test_soma();
    test_maior_numero();
    test_maior_elemento();
    test_calculadora();
    test_media_notas();
    test_maior_media();
    test_criar_personagem();
    test_duelo();
    return 0;
}


