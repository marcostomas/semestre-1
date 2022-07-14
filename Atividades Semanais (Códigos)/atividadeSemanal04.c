#include <stdio.h>
#include <math.h>

// Exercício 1

void areaTrapezio(double baseMaior, double baseMenor, double altura){
	double area = (baseMaior + baseMenor)*altura/2;
	printf("\nUm trapezio de base menor igual a %f, base maior igual a %f e uma altura igual a %f, \n tem a seguinte area: %f", baseMenor, baseMaior, altura, area);
}

int main(){
	double baseMenor, baseMaior, altura;
	
	printf("De um valor para a base menor do trapezio \n"); 
	scanf("%f", &baseMenor);
	
	printf("\nDe um valor para a base maior do trapezio \n");
	scanf("%f", &baseMaior);

	printf("\nDe um valor para a altura do trapezio \n");
	scanf("%f", &altura);

	areaTrapezio(baseMaior, baseMenor, altura);
	return 0;

}

// Exercício 2

/*
double areaRetangulo(double base, double altura){
	double area = areaTrapezio(base,base,altura);
	printf("Area do retangulo: %f\n", area);
	return area;
}

int main (){
	areaRetangulo(11,27);
	return 0;
}

Saída: 'Area do retangulo: 297.000000'
*/

// Exercício 3

/*
void areaDoQuadrado(double lado){
	areaRetangulo(lado, lado);
	double area = pow(lado,2);
	printf("Area do quadrado: %f\n",area);
}

int main(){
	areaDoQuadrado(15);
	return 0;
}
*/