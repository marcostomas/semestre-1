#include <stdio.h>

void main(){
	int tam = 0;
	
	printf("Entre com o tamanho do array: ");
	scanf("%d", &tam);
	
	int* arr = (int*) malloc(sizeof(int) * tam);
	
	int val = 0;
	
	for(int i = 0; i < tam ; i++){
		printf("\n Digite um valor para coloca-lo no array: ");
		
		scanf("%d", &val);
		arr[i] = val;
	}
	contagem1(arr, tam, 5);
}


int contagem1 (int* valores, int n, int x){
	int k = 0;
	
	for(int i = 0; i < n-1 ; i++){
		if (valores[i] == x) k++;
	}
  printf("O numero de vezes em que %d aparece é: %d", x, k );
	return k;
}
