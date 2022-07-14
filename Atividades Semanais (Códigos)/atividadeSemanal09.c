#include <stdio.h>
#include <stdlib.h>

double* somaPolinomios(double* p, double* q, int n)
{

	double *saida = (double *)malloc(sizeof(double) * n);

	for (int k = 0; k < n; k++)
	{
		saida[k] = p[k] + q[k];
		printf("\n A soma dos coeficientes quando x^%d é igual a: %.2f", k, saida[k]);
	}

	return saida;
}

void main()
{

	int tam;

	printf("Escolha um valor para o tamanhos dos arranjos: ");
	scanf("%d", &tam);

	double* arr1 = (double*) malloc(sizeof(double) * tam);
	double* arr2 = (double*) malloc(sizeof(double) * tam);

	double val = 0;

	for (int i = 0; i < tam; i++)
	{
		printf("\n Qual o valor que você quer colocar na posicao %d do arranjo 1? ", i);
		scanf("%lf", &val);
		arr1[i] = val;
	}

	for (int i = 0; i < tam; i++)
	{
		printf("\n Qual o valor que você quer colocar na posicao %d do arranjo 2? ", i);
		scanf("%lf", &val);
		arr2[i] = val;
	}

	somaPolinomios(arr1, arr2, tam);
}
