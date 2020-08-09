/**************
Questao 02
Mailson Felipe
***************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checaPermutacaoParcial(char *palavra_01, char *palavra_02)
{
	int letrasTrocadas = 0, i;
	
	// Se o primeiro caracter da primeira palavra nao for igual ao primeiro caracter da segunda palavra,
	// ou se seus tamanhos forem diferentes, as palavras nao atendem aos requisitos
	if(palavra_01[0] != palavra_02[0] || strlen(palavra_01) != strlen(palavra_02)) 
	{
		return false;
	}

	for(i=1; i<strlen(palavra_02); i++)
	{
		if(palavra_02[i] != palavra_01[i]) // verifica disparidade nas posicoes das duas strings
		{
			letrasTrocadas++;
		}
	}

	if(strlen(palavra_02) > 3)
	{
		if(letrasTrocadas < strlen(palavra_02)*(2.0/3.0)) //se 2/3 dos caracteres mudaram de posicao em comparacao as posicoes originais
		{
			return true;
		}
	}else{
		if(letrasTrocadas) // Se a palavra for menor do que 3 e houver letras trocadas
		{
			return true;
		}else{
			return false;
		}
	}

	return false;
}


int main()
{	
	if(checaPermutacaoParcial("you", "yuo"))
	{
		printf("true\n");
	}else{
		printf("false\n");
	}

	return 0;
}