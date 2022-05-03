#include <stdio.h>

int main(void){
	/* a: altura
		l: largura
		a1: area da sala
		a2: area do quarto/banheiro
		a3: area total da casa
	*/
	
	int a = 10;
	int l = 17;
	int a1 = a*(l-7);
	int a2 = (a-5)*(l-10);
	int a3 = a*l;
	
	printf("A area da sala e de %d metros quadrados\n", a1);
	printf("As areas do quarto e do banheiro sao, cada uma, de %d metros quadrados\n", a2);
	printf("A area da casa e de %d metros quadrados\n", a3);
	return 0;
}