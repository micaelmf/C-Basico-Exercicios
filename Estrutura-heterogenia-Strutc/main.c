#include <stdio.h>

/*Q1: Soma */
/* Utilizando a struct abaixo, crie uma funÁ„o que recebe uma struct "numeros"ù
  e retorna a soma de a e b. */

typedef struct{
    int a;
    int b;
}Numeros;

int soma(Numeros n){
    return n.a + n.b;
}

/*Q2: Maior N˙mero */
/*Escreva uma funÁ„oo que recebe uma vari·vel do tipo "numeros"ù e retorna o maior entre a e b.*/
int maiorNumero(Numeros n){
	int maior = 0;
	
	if (n.a > n.b){
		maior = n.a;
	}else{
		maior = n.b;
	}
	
    return maior;
}

/* Q3:  Maior Elemento */
/* Crie uma funÁ„oo que recebe como argumento uma struct "vetor"ù, e retorna o maior elemento
  desse vetor.*/
typedef struct{
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
/* Vamos alterar agora a struct "numeros"ù, ambas as vari·veis a e b agora s„o do
   tipo float e ser· acrescentado mais uma vari·vel do tipo char chamada "operador"ù,
   ela deve conter o tipo de operaÁ„o que ser· realizada entre a e b.
   Utilizando a nova struct, crie uma funÁ„o que retorna o resultado da operaÁ„o
   realizada entre a e b, onde a operaÁ„o a ser realizada √© soma ("ò+"ô), subtraÁ„o ("ò-"ô),
   divis„o ("ò/"ô) ou multiplicaÁ„o ("ò*"ô), dependendo do tipo de operaÁ„o armazenada
   na vari·vel "operador"ù */

typedef struct{
    float a;
    float b;
    char operador;
}Numeros2;

float calcular(Numeros2 n){
	float result;
	
	
	if(n.operador == '+'){
		result = n.a + n.b;
	}else if(n.operador == '-'){
		result = n.a - n.b;
	}else if(n.operador == '*'){
		result = n.a * n.b;
	}else if(n.operador == '/'){
		result = n.a / n.b;
	}else{
		printf("Operador n„o identificado\n");
	}
	
    return result;
}

/* Q5: MÈdia das Notas */
/* Utilizando a struct "aluno"ù definida abaixo, crie uma funÁ„o que calcula e retorna
  a mÈdia das trÈs notas contidas no vetor "notas"ù. */

typedef struct{
    int matricula;
    float notas[3];
}Aluno;

float media(Aluno a){
	float media = 0;
	int i;
	
	for(i = 0; i < 3; i++){
		media += a.notas[i];
	}
	
	media = media/3;
	
    return media;
}

/* Q6: Maior MÈdia */
/* Com a struct e a funÁ„o criada na quest„o anterior, crie uma nova funÁ„o, que recebe um
  vetor de n alunos como argumento, e retorna o n˙mero de matricula do aluno com maior mÈdia. */

int maiorMedia(Aluno a[], int n){
	int i;
	float melhor = 0, matricula = 0;
	
	for(i = 0; i < 3; i++){
		if(melhor < media(a[i])){
			melhor = media(a[i]);
			matricula = a[i].matricula;
		}
	}
	
    return matricula;
}


/* Construir Personagem */

/* A struct "personagem" contÈm os atributos de um personagem em um jogo de RPG, utilizando
  essa struct e a funÁ„o criarPersonagem construa um novo personagem. */

typedef struct
{
    int vida;
    int ataque;
}Personagem;

Personagem criarPersonagem(int vida, int ataque){
    Personagem p;
    
	p.vida = vida;
    p.ataque = ataque;
    
    return p;
}

/* Q8: Duelo */
/* Agora vamos criar a funÁ„o "duelo", ela recebe dois personagens e faz os dois duelar.
A funÁ„o deve retornar 1 se o personagem a ganhar e 0 caso contr·rio.
Dicas: Utilize um laÁo while e enquanto os dois personagens estiverem vivos, ou sej·
a vida dos dois for maior que 0, os dois devem continuar se atacando.
Quando o personagem a ataca o b, a quantidade de vida que o personagem b perde
È igual ao ataque de a, a mesma coisa acontece quando b ataca a. */

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

/**ImplementaÁ„o das funÁıes de teste **/

void test_soma(){
    printf("---------------------\n");
    printf("teste Soma\n");
    Numeros n = {5, 5};
    if(soma(n) == 10){
        printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

void test_maior_numero(){
    printf("---------------------\n");
    printf("teste Maior Numero.\n");
    Numeros n = {1, 2};
    if(maiorNumero(n) == 2){
        printf("    ok.\n");
    }else{
        printf("    not ok.\n");
    }
}

void test_maior_elemento(){
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
    if(calcular(n) == 10 || calcular(n) == 0 || calcular(n) == 25 || calcular(n) == 1){
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
