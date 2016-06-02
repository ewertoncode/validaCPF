#include <stdio.h>

int charToInt(char c)
{
	return c - '0';	
}

int validaCPF(char *cpf) 
{

	int somatorioDigito1 = 0;
	for(int i = 0; i < 9; i++) {
		somatorioDigito1 += charToInt(cpf[i]) * (i + 1); 
	}
	int primeiroDigito;
	primeiroDigito = somatorioDigito1 % 11;
	
	int somatorioDigito2 = 0;
	for(int i = 0; i < 9; i++) {
		somatorioDigito2 += charToInt(cpf[i]) * i; 
	}
	somatorioDigito2 += primeiroDigito * 9;
	int segundoDigito;
	segundoDigito = somatorioDigito2 % 11;
	
	if(charToInt(cpf[9]) == primeiroDigito && charToInt(cpf[10]) == segundoDigito) return 1;	
		
	return 0;
	
}


int main(int argc, char **argv)
{
	char cpf[11];
	
	printf("Informe seu cpf: ");
	scanf(" %s", cpf);
	
	if(validaCPF(cpf)) {
		printf("CPF Válido");
	} else {
		printf("CPF Inválido");
	}
	
	
	return 0;
}

