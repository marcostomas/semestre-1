#include <stdio.h>

void retangulo(int largura, int altura){
	for(int j = 0; j < altura; j++){
		printf("\n");
		
		for (int i = 0; i < largura; i++){
			printf("#");
		}
	}
	
}


void main(){
	int l, a;
	printf("Forneca valores de largura e altura, respectivamente, separados por virgula \n");
	scanf("%i , %i", &l, &a);
	retangulo(l, a);
}