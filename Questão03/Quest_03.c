/**************
Questao 03
Mailson Felipe
***************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Verifica o modulo da diferenca do tamanho entre duas palavras
int difTamanho(char *palavra_01, char *palavra_02)
{
	return abs(strlen(palavra_01) - strlen(palavra_02));
}


bool verificaErro(char *palavra_01, char *palavra_02)
{

	int diferencas = 0, indicePalavra_01, indicePalavra_02;

	// Se a diferenca entre as palavras for maior que um, mais de uma letra esta faltando e,
	// portanto, nao pode ser um typo como descrito no desafio.

	if(difTamanho(palavra_01, palavra_02) > 1)
	{
		return false;
	}

	indicePalavra_01 = indicePalavra_02 = 0; 

	// Enquanto os indices nao atingirem o tamanho das palavras
	while(strlen(palavra_01) > indicePalavra_01 && strlen(palavra_02) > indicePalavra_02)
	{
		if(palavra_01[indicePalavra_01] != palavra_02[indicePalavra_02]) // encontrando diferenca. Somente uma eh permitida
		{
			if(diferencas != 0)
			{
				return false; // se entrar uma segunda vez e a flag tiver sido resetada, mais de uma diferenca foi encontrada
			}

			if (strlen(palavra_01) > strlen(palavra_02)) // (1) so pode ser um typo do tipo caracter faltante
			{
				indicePalavra_01++; // acompanha o proximo caraterer, que deve ser igual ate o final, caso seja true

			}else if(strlen(palavra_02) > strlen(palavra_01)){ // o mesmo (1) ocorre aqui, mas com a segunda palavra
				indicePalavra_02++;
			}else{
				indicePalavra_01++; // caso as palavras tenham tamanhos iguais, os indices incrementam juntos
				indicePalavra_02++;
			}

			diferencas++; // conta as disparidades encontradas

		}else{ // caso contrario (caracteres iguais nas respectivas posicoes), os indices incrementam juntos
			indicePalavra_01++;
			indicePalavra_02++;
		}
	}
	
	return true;	
}


int main()
{
	bool x = verificaErro("pale", "bake");
	if (x == true)
	{
		printf("true\n");
	}else{
		printf("false\n");
	}

	return 0;
}