#include <stdio.h>

void cor(int identificador){
	switch(identificador){
	
		case 1:
			printf("Verde \n");
			break;
		case 2:
			printf("Amarelo \n");
			break;
		case 3:
			printf("Azul \n");
			break;
		case 4:
			printf("Branco \n");
			break;
		default:
			 printf("Identificador invalido! \n");
			 break;
	}
}

void conjecturaDeCollatz(int n){
	printf("Imprimindo sequencia iniciando em %i\n", n);
	while (n>1){
		if (n % 2 == 0) n = n/2;
		else n = 3*n + 1;
		printf("%i\n",n);
	}
}

void main(){
	cor(1);
	cor(2);
	cor(3);
	cor(4);
	cor(12);
	
	conjecturaDeCollatz(51);
}

/*
	Para o parâmetro 51 a saída foi:
	
	Imprimindo sequencia iniciando em 51
	154
	77
	232
	116
	58
	29
	88
	44
	22
	11
	34
	17
	52
	26
	13
	40
	20
	10
	5
	16
	8
	4
	2
	1
*/