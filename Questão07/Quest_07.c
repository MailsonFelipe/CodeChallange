/**************
Questao 07
Mailson Felipe
***************/

#include <stdio.h>
#include <stdlib.h>

//Struct utilizada
typedef struct no
{
	char info;
	struct no *prox;

}tipoNo;


void imprimeLista(tipoNo *lista)
{
	tipoNo *auxLista;

	for (auxLista = lista; auxLista != NULL; auxLista = auxLista->prox)
	{
		printf("%c ", auxLista->info);
	}

	printf("\n");
}


// Retorna o tamanho da lista
int tamanhoLista(tipoNo *lista)
{
	int tam;
	tipoNo *auxLista;

	tam = 0;
	auxLista = lista;

	while(auxLista != NULL)
	{
		auxLista = auxLista -> prox;
		tam++;
	}

	return tam;
}

// encontra a intersecao comparando se um no aponta para o mesmo endereco de memoria de um outro
int encontraIntersec(tipoNo *listaMaior, tipoNo *listaMenor, int difTam)
{
	tipoNo *auxListaMaior, *auxListaMenor;
	int i;

	auxListaMaior = listaMaior;
	auxListaMenor = listaMenor;

	for(i=0; i<difTam; i++)
	{
		auxListaMaior = auxListaMaior->prox; // para "alcancar" o incicio da lista menor, em tamanho
	}


	while(auxListaMaior != NULL && auxListaMenor != NULL)
	{
		if(auxListaMaior == auxListaMenor) // verifica se apontam para o mesmo espaco de memoria
		{
			printf("Intersecao: %c\n", auxListaMaior->info);
			return 0;
		}

		auxListaMaior = auxListaMaior->prox;
		auxListaMenor = auxListaMenor->prox;
	}

	printf("Nao ha intersecoes.\n");
	return 0;
}

void insereElementoLista(tipoNo *lista, char info)
{
	tipoNo *novoElemento, *auxLista;
	novoElemento = (tipoNo*) malloc(sizeof(tipoNo));
	novoElemento->info = info;
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

// Funcao para caminhar na lista e devolver o elemento que se deseja apontar
tipoNo *caminhaLista(tipoNo *lista, int limite)
{
	int i;
	tipoNo *auxLista = lista;

	for(i=0; i<limite; i++)
	{
		auxLista = auxLista->prox;
	}

	return auxLista;
}



int main()
{

	tipoNo *pLista1 = malloc(sizeof(tipoNo));
	tipoNo *pLista2 = malloc(sizeof(tipoNo));
	int tamLista_01, tamLista_02;

	pLista1->prox = NULL;
	pLista2->prox = NULL;

	/*Exemplo da descricao*/
	insereElementoLista(pLista1, 'C');
	insereElementoLista(pLista1, 'A');
	insereElementoLista(pLista1, 'E');
	insereElementoLista(pLista1, 'H');
	insereElementoLista(pLista1, 'J');
	insereElementoLista(pLista1, 'B');
	insereElementoLista(pLista1, 'A');

	insereElementoLista(pLista2, 'D');
	insereElementoLista(pLista2, 'F');

	pLista2->prox->prox->prox = caminhaLista(pLista1, 5);

	imprimeLista(pLista1);
	imprimeLista(pLista2);

	tamLista_01 = tamanhoLista(pLista1);
	tamLista_02 = tamanhoLista(pLista2);

	(tamLista_01 > tamLista_02) ? encontraIntersec(pLista1, pLista2, tamLista_01 - tamLista_02) 
	: encontraIntersec(pLista2, pLista1, tamLista_02 - tamLista_01);

	return 0;
}