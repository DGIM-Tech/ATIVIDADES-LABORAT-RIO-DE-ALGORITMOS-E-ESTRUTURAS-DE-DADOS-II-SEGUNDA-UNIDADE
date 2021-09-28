// 2 letra C
#include <stdio.h>
#include <stdlib.h>
#define TAM 7
// criando a strutura para lista encadeada
typedef struct no
{
	int chave;
	struct no *proximo;
}No;

typedef struct 
{
	No *inicio;
	int tam;
}Lista;
// incializando a lista encadeada
void inicilzarLista(Lista *l){
	l->inicio = NULL;
	l->tam = 0;
}
// inserindo na lista encadeada
void inseriLista(Lista *l, int valor)
{
	No *novo = malloc(sizeof(No));
	if(novo){
		novo->chave = valor;
		novo->proximo = l->inicio;
		l->inicio = novo;
		l->tam++;
	} 
	else
	{
		printf("erro ao alocar memoria \n");
	}
}


// funçao de imprimi usanndo lista encadeada
void imprimiLista(Lista *l){
	No *aux = l->inicio;
	printf("tam %d: ", l->tam);
	while(aux){
		printf("%d ", aux->chave);
		aux = aux->proximo;
	}
	
} 
// para iniciliza a tabela
void inicializarTabela(Lista t[])
{
	int i;
	for(i = 0; i < TAM; i++)
	{
	inicilzarLista(&t[i]);
	}
}
// funça de divisao
int funcaodiv(int chave)
{
	return chave % TAM;
}
void inserir(Lista t[],int valor)
{
	int id = funcaodiv(valor);
 	inseriLista(&t[id], valor);
	 
}


void imprimir(Lista t[]) 
{
	int i;
	for(i = 0; i < TAM; i++){
		printf("%d = ", i);
		imprimiLista(&t[i]);
		printf("\n");
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
int main()
{
	int op, valor;
	Lista tabela[TAM];
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
		printf("saindo....\n");
		exit(0);
		default:
			printf("opcao invalida!\n");
			break;
		}
		
	} while(op != 3); 
	
	
	return 0;
}