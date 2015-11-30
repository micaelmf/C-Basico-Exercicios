#include <stdio.h>

int random();
void dicas(int num, int resp, int tent);

int main()
{
    int continuar=1,
        resp,
        tent,
        num,
        n;

    do{
        system("cls || clear");
        resp = random();

        printf("Comecou! Tente adivinhar o numero!\n\n");
        tent = 0;

        do{
            tent++;
            printf("Tentativa %d: ", tent);
            scanf("%d", &num);
            dicas(num,resp,tent);
        }while( num != resp);

        printf("Digite 0 para sair, ou qualquer outro numero para continuar: ");
        scanf("%d", &continuar);
    }while(continuar);

}

int random()
{
    int n;
    printf("Insira o valor maximo que pode ser sorteado: ");
    scanf("%d", &n);
    printf("Sorteando numero entre 1 e %d...\n",n);
    srand((unsigned)time(NULL));
    return (1+rand()% n);
}

void dicas(int num, int resp, int tent)
{

	float porcento = 0;
	porcento = ((((double) num/resp)-1)*100);
	
	if(porcento < 0){
		porcento *= -1;
	}
	
	if (porcento == 0){
		printf("Parabens! Voce acertou o numero em %d tentativas!\n\n", tent);
	}else if (porcento > 0 && porcento < 10){
		printf("Muito quente\n\n");
	}else if (porcento > 10 && porcento < 20){
		printf("Quente\n\n");
	}else if (porcento > 20 && porcento < 30){
		printf("Frio\n\n");
	}else if (porcento > 30 && porcento < 40){
		printf("Muito frio\n\n");
	}else if (porcento > 40){
		printf("Continue tentando\n\n");
	}else{
		printf("Erro!\n\n");
	}

}

