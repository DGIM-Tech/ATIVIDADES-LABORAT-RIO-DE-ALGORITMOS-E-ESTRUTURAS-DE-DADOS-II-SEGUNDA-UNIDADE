#include <stdio.h>
#include <stdlib.h>
#define TAM 7 

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
void inicilzarLista(Lista *l){ // para inicializa a lisata encadeada
	l->inicio = NULL;
	l->tam = 0;
}
int funcaoDiv(int chave) // funçao divisao
{
	return chave % TAM;
}
void inseriLista(Lista *l, int valor) // para inseri na lista
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

int buscaLista(Lista *l, int valor){ // para busca na lista
	No *aux = l->inicio;


	while(aux && aux->chave != valor)

		aux = aux->proximo;
		if(aux)
			return aux->chave;
	return 0;
}

void imprimiLista(Lista *l){ // para imprimir na lista
	No *aux = l->inicio;
	printf("tam %d: ", l->tam);
	while(aux){
		printf("%d ", aux->chave);
		aux = aux->proximo;
	}
	
} 
void inserir(Lista t[],int valor)
{
	int id = funcaoDiv(valor);
 	inseriLista(&t[id], valor);
	 
}
void remover(Lista *l, int valor) // removendo o item da tabela
{
    No *aux = l->inicio;
    No *anterior;
    int cont = 0;
    if (l->inicio != NULL)
    {
        //encontrar o anterior
        while (aux != NULL && aux->chave != valor)
        {
            anterior = aux;
            aux = aux->proximo;
         
        }
        while (aux != NULL)
        {
            if (aux->chave == (valor))
            {
                if (aux == l->inicio)
                {
                    l->inicio = aux->proximo;
                }
                else
                {
                    anterior->proximo = aux->proximo;
                }
                cont++;
                printf("%d foi removido com sucesso!\n", aux->chave);
                free(aux);
                break;
            }
            aux = aux->proximo;
        }
    }
    if (cont == 0)
    {
        printf("valor nao encontrado!\n");
    }
   
}

void inicializarTabela(Lista t[])
{
	int i;
	for(i = 0; i < TAM; i++)
	{
	inicilzarLista(&t[i]);
	}
}


int busca(Lista t[], int chave) 
{
	int id = funcaoDiv(chave);
	printf("\n indice gerado: %d\n", id);
	printf("\nIndece gerada: %d\n", id);
	return buscaLista(&t[id], chave);
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
void apagar(Lista t[], int valor){ 
	int id = funcaoDiv(valor);
   remover(&t[id], valor);
  
   printf("\n");
}
void menu(){
	printf("1 -  para inserir\n");
	printf("2 -  para buscar\n");
	printf("3 -  mostra tabela\n");
	printf("4 -  para remover\n");
	printf("5 -  sair\n");
	printf("\n");
}
int main()
{
	int op, valor,retono;
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
			printf("qual valor voce deseja busca: ");
			scanf("%d", &valor);
			retono = busca(tabela, valor);
			if(retono != 0)
			{
				printf("valor encontrado: %d\n", valor);
			}
			else
			{
				printf("valor nao encontrado \n");
			}
			break;
		case 3: 
			imprimir(tabela);
			break;
		case 4: 
			printf("digite o valor que voce deseja remover: ");
			scanf("%d", &valor);
			apagar(tabela,valor);
			break;
		case 5:
			printf("saindo......\n");
			break;
		default:
			printf("opcao invalida!\n");
			break;
		}
		
	} while(op != 5); 
	
	
	return 0;
}