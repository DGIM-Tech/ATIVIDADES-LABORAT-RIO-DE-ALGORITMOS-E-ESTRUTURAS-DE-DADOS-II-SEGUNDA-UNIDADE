//1 letra A funçao dobra
#include <stdio.h>
#include <stdlib.h>
#define TAM 7

void inicializarTabela(int t[])
{
	int i;
	for(i = 0; i < TAM; i++)
	{
		t[i] = 0;
	}
}

int funcaoDobra(int chave){
	int num_bits = chave;
	int parte1 = chave >> num_bits;
	int parte2 = chave & TAM;
	return (parte1 ^ parte2);
	
}

void inserir(int t[],int valor)
{
	int id = funcaoDobra(valor);
	while(t[id] != 0)
	{
		id = funcaoDobra(id + 1);
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

void menu()
{
	printf("\n");
	printf("1 - inseir\n");
	printf("2 - imprimir\n");
	printf("3 - sair\n");
	printf("\n");
}
int main(int argc, char** argv)
{
	int op, valor, tabela[TAM];
	inicializarTabela(tabela);
	do
	{
		menu();
		scanf("%d", &op);
		switch(op)
		{
		case 1:
			printf("Qual valor voce deseja inserir: ");
			scanf("%d", &valor);
			inserir(tabela, valor);
			break;
		case 2:
			imprimir(tabela);
		
			break;
		case 3: 
			printf("saindo......\n");
			break;
		default:
			printf("opcao invalida!\n");
			break;
		}
		
	} while(op != 3); 
	
	
	return 0;
}
 
// 1 letra B função multiplicação 
#include <stdio.h>
#include <stdlib.h>
#define TAM 7

void inicializarTabela(int t[])
{
	int i;
	for(i = 0; i < TAM; i++)
	{
		t[i] = 0;
	}
}

int funacaomult(int chave){ 
	float a = 0.6180339887;
	float value = chave * a;
	value = value - (int) value;
	return (int) (TAM * value);
}
void inserir(int t[],int valor)
{
	int id = funacaomult(valor);
	while(t[id] != 0)
	{
		id = funacaomult(id + 1);
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

void menu()
{
	printf("\n");
	printf("1 - inseir\n");
	printf("2 - imprimir\n");
	printf("3 - sair\n");
	printf("\n");
}
int main(int argc, char** argv)
{
	int op, valor, tabela[TAM];
	inicializarTabela(tabela);
	do
	{
		menu();
		scanf("%d", &op);
		switch(op)
		{
		case 1:
			printf("Qual valor voce deseja inserir: ");
			scanf("%d", &valor);
			inserir(tabela, valor);
			break;
		case 2:
			imprimir(tabela);
		
			break;
		case 3: 
			printf("saindo......\n");
			break;
		default:
			printf("opcao invalida!\n");
			break;
		}
		
	} while(op != 3); 
	
	
	return 0;
}


// questao 1 letra C função divisão
#include <stdio.h>
#include <stdlib.h>
#define TAM 7

void inicializarTabela(int t[])
{
	int i;
	for(i = 0; i < TAM; i++)
	{
		t[i] = 0;
	}
}

int funcaoDiv(int chave)
{
	return chave % TAM; 
}

void inserir(int t[],int valor)
{
	int id = funcaoDiv(valor);
	while(t[id] != 0)
	{
		id = funcaoDiv(id + 1);
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

void menu()
{
	printf("\n");
	printf("1 - inseir\n");
	printf("2 - imprimir\n");
	printf("3 - sair\n");
	printf("\n");
}
int main(int argc, char** argv)
{
	int op, valor, tabela[TAM];
	inicializarTabela(tabela);
	do
	{
		menu();
		scanf("%d", &op);
		switch(op)
		{
		case 1:
			printf("Qual valor voce deseja inserir: ");
			scanf("%d", &valor);
			inserir(tabela, valor);
			break;
		case 2:
			imprimir(tabela);
		
			break;
		case 3: 
			printf("saindo......\n");
			break;
		default:
			printf("opcao invalida!\n");
			break;
		}
		
	} while(op != 3); 
	
	
	return 0;
}