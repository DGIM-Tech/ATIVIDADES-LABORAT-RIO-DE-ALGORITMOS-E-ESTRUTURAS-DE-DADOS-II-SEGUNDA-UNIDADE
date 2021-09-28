// 2 letra B
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
int funcaodiv(int chave)
{
	return chave % TAM;
}
void inserir(int t[],int valor)
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
			printf("\tQual valor voce deseja inserir: ");
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