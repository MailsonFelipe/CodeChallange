/**************
Questao 05
Mailson Felipe
***************/

#include <stdio.h>
#include <stdlib.h>

// Struct utilizada
typedef struct no
{
	char mensagem;
	struct no *prox;

}tipoNo;


void imprimeLista(tipoNo *lista)
{
	tipoNo *auxLista;

	for (auxLista = lista; auxLista != NULL; auxLista = auxLista->prox)
	{
		printf("%c ", auxLista->mensagem);
	}

	printf("\n");
}

// Insere elemento no final
void insereElementoLista(tipoNo *lista, char mensagem)
{
	tipoNo *novoElemento, *auxLista;
	novoElemento = (tipoNo*) malloc(sizeof(tipoNo));
	novoElemento->mensagem = mensagem;
	novoElemento->prox = NULL;

	if(lista == NULL)
	{
		lista = novoElemento;
	
	}else{
		auxLista = lista;

		while(auxLista->prox != NULL)
		{
			auxLista = auxLista->prox;
		}

		auxLista->prox = novoElemento;
	}
}

// Recebe como parametro a lista e o elemento (endereco) a ser excluido
void removeNo (tipoNo *lista, tipoNo *del)
{
   tipoNo *noAtual, *noProx;

   noAtual = lista;
   noProx = lista->prox;

   while (noProx != NULL && noProx != del)
   {
      noAtual = noProx;
      noProx = noProx->prox;
   }

   if (noProx != NULL)
   {
      noAtual->prox = noProx->prox;
      free (noProx);
   }
}

// Dois lacos que percorrem a lista. Um indice esta sempre a frente do outro, de modo que o no mais
// externo seja analisado com o restante dos elementos depois dele proprio
void excluiMensagensDuplicadas(tipoNo *lista)
{
	tipoNo *noAtual, *noProx;

	for (noAtual = lista->prox; noAtual != NULL; noAtual = noAtual->prox)
	{
		noProx = noAtual->prox;
		while(noProx != NULL)
		{
			if(noAtual->mensagem == noProx->mensagem)
			{
				removeNo(lista, noProx);
			}
			noProx = noProx->prox;
		}
	}
}


int main()
{
	tipoNo *pLista = malloc(sizeof(tipoNo));
	pLista->prox = NULL;

	insereElementoLista(pLista, 'A');
	insereElementoLista(pLista, 'B');
	insereElementoLista(pLista, 'C');
	insereElementoLista(pLista, 'D');
	insereElementoLista(pLista, 'A');
	insereElementoLista(pLista, 'A');
	insereElementoLista(pLista, 'B');
	insereElementoLista(pLista, 'C');
	insereElementoLista(pLista, 'D');
	insereElementoLista(pLista, 'A');

	printf("Antes:");
	imprimeLista(pLista);

	excluiMensagensDuplicadas(pLista);
	
	printf("Depois:");
	imprimeLista(pLista);
	return 0;
}