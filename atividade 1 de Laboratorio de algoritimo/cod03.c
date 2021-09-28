#include <stdio.h>
#include <stdlib.h>
#define TAM 7 
#define TAMM 7
#define TAMD 7

void inicializarDiv(int t[])
{
	int i;
	for(i = 0; i < TAM; i++)
	{
		t[i] = 0;
	}
}
void inicializarTabelamMult(int tm[])
{
	int j;
	for(j = 0; j < TAMM; j++)
	{
		tm[j] = 0;
	}
}
void inicializarTabelaDobra(int td[])
{
	int z;
	for(z = 0; z < TAMD; z++)
	{
		td[z] = 0;
	}
}
int funcaodiv(int chave)
{
	return chave % TAM;
}
int funcaoMult(int chave1){
	float a = 0.6180339887;
	float value = chave1 * a;
	value = value - (int) value;
	return (int) (TAMM * value);
}
int funcaoDobra(int chave2){
	int num_bits = chave2;
	int parte1 = chave2 >> num_bits; 
	int parte2 = chave2 & TAMD;
	return (parte1 ^ parte2);
	
}
void inserirMult(int tm[], int valor)
{
	int idm = funcaoMult(valor);
	while(tm[idm] != 0)
	{
		idm = funcaoMult(idm + 1);
	}
	tm[idm] = valor;
}
void inserirdobra(int td[], int valor1)
{
	int idd = funcaoDobra(valor1);
	while(td[idd] != 0)
	{
		idd= funcaoDobra(idd + 1);
	}
	td[idd] = valor1;
}
void inserirDiv(int t[], int valor)
{
	int id = funcaodiv(valor);
	while(t[id] != 0)
	{
		id = funcaodiv(id + 1);
	}
t[id] = valor;
}

void imprimir(int t[])
{
	int i;
	for(i = 0; i < TAM; i++)
	{
	printf("%d = %d\n", i , t[i]);
}
}
void imprimirMult(int tm[]) // tm para multiplicaçao
{
	int j; // para multiplicçao
	for(j = 0; j < TAMM; j++)
	{
		printf("%d = %d\n", j , tm[j]);
	}
}
void imprimirDobra(int td[]) // tm para multiplicaçao
{
	int z; // para dobra
	for(z = 0; z < TAMD; z++)
	{
		printf("%d = %d\n", z , td[z]);
	}
}

void menu1()
{
	printf("\n");
	printf("para funcao de dobra\n");
	printf("1 - inseir\n");
	printf("2 - imprimir tabela com dobra\n");
	printf("7 - sair\n");
	printf("\n");
}
void menu2()
{
	printf("\n");
	printf("para funcao de multiplicao\n");
	printf("3- inseir\n");
	printf("4 - imprimir tabela com multiplicao\n");
	printf("7 - sair\n");
	printf("\n");
}
void menu3()
{
	printf("\n");
	printf("para funcao da divisao\n");
	printf("5 - inseir\n");
	printf("6 - imprimir tabela com divisao\n");
	printf("7 - sair\n");
	printf("\n");
}
int main(int argc, char** argv)
{
	int op, valor, tabela[TAM], tabelamult[TAMM], tabelaDobra[TAMD];
	inicializarDiv(tabela);
	inicializarTabelamMult(tabelamult);
	inicializarTabelaDobra(tabelaDobra);
	
	do
	{ 
	menu1();
	menu2();
		menu3();
		scanf("%d", &op);
		switch(op)
		{
		case 1:
			printf("Qual valor voce deseja inserir: ");
			scanf("%d", &valor);
			inserirdobra(tabelaDobra,valor);
			break; 
		case 2:
		imprimirDobra(tabelaDobra);
			break;
		case 3:
			printf("Qual valor voce deseja inserir: ");

			scanf("%d", &valor);
			inserirMult(tabelamult,valor);
			break;
		   case 4:
		   	imprimirMult(tabelamult);
		   	break;
		   
		   case 5:
		   		printf("Qual valor voce deseja inserir: ");
			scanf("%d", &valor);
		inserirDiv(tabela, valor);
		   	break;
		   case 6: 
		  		imprimir(tabela);
		   	break;
		case 7:
			printf("saindo......\n");
			break;
		default:
			printf("opcao invalida!\n");
			break;
		}

	}
	while(op != 7); 


	return 0;
}
