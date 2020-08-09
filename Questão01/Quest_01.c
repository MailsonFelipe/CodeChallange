/**************
Questao 01
Mailson Felipe
***************/

#include <stdio.h>
#include <string.h>

int contaEspacos(char *string) // Recebe a frase como parametro
{
	int i, qtdEspacos;

	qtdEspacos = 0;

	for (i = 0; i < strlen(string); ++i)
	{
		if(string[i] == ' ') // Conta a quantidade de espacos
		{
			qtdEspacos ++;
		}
	}

	return qtdEspacos;
}

void substituiEspacos(char *frase, int tamanhoLiteral)
{
	int i, j, novoTamanho;

	novoTamanho = tamanhoLiteral + (contaEspacos(frase)*2);

	i = novoTamanho - 1; // indice para controlar o novo tamanho (maior)
	j = tamanhoLiteral - 1; // indice para controlar o tamanho antigo (menor)

	while(j > 0)
	{
		if(frase[j] != ' ')
		{
			frase[i] = frase[j]; // Copia para a última posição do novo tamanho enquanto nao houver espaco
			i--;	
		}else{ // Copia dos novos caracteres
			frase[i] = '2';
			frase[--i] = '3';
			frase[--i] = '&';
			i--;
		}
		j--;
	}

	// Saida
	for(i=0; i<novoTamanho; i++)
	{
		printf("%c", frase[i]);
	}

	printf("\n");
}

int main()
{
	char *frase;
	int i, j, tamanhoLiteral;

	scanf("%[^\n]s", frase); //Input da string
	scanf("%d", &tamanhoLiteral); //Input do tamanho da string

	substituiEspacos(frase, tamanhoLiteral);

	return 0;
}