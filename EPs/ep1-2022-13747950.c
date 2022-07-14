/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   Turma 04 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <Marcos Paulo Tomás Ferreira>             <13747950>          **/
/**                                                                 **/
/*********************************************************************/

/*
	Implementacao de diversas funcoes matematicas
*/

#include <stdio.h>
#include <math.h>

/* Variaveis globais utilizas pela função separaNumero */
int unidades;
int dezenas;
int centenas;
int milhares;

/*
	Separa o valor de entrada em unidades, dezenas, centenas e milhares.

	Se o numero passado como parametro for menor que zero ou maior que 9999,
	a função devera colocar o valor -1 nas quatro variaveis globais
	existentes no programa: unidades, dezenas, centenas e milhares.

	Caso contrario, a função devera separar o numero de acordo com suas
	unidades, dezenas, centenas e milhares e colocar esses valores nas
	respectivas variaveis globais.
	Isto e, para o numero 2345, deve atribuir o valor 2 na variavel
	milhares, o valor 3 na variavel centenas, o valor 4 na variavel dezenas
	e o valor 5 na variavel unidades.

	Parametro:
		valor - Valor a ter seus digitos separados
*/
void separaNumero(int valor)
{
	if (valor >= 0 && valor <= 9999)
	{
		unidades = valor % 10;
		dezenas = (valor / 10) % 10;
		centenas = (valor / 100) % 10;
		milhares = (valor / 1000) % 10;

		printf("milhar: %i, centena: %i, dezena: %i, unidade: %i", milhares, centenas, dezenas, unidades);
	}
	else
	{
		unidades = -1;
		dezenas = -1;
		centenas = -1;
		milhares = -1;

		printf("milhar: %i, centena: %i, dezena: %i, unidade: %i", milhares, centenas, dezenas, unidades);
	}
}

/*
	Suponha que a população de um país A seja da ordem de "popA" habitantes com uma taxa anual de crescimento de
	"taxaA" (em %) e que a população de B seja "popB" habitantes com uma taxa de crescimento de "taxab" (em %).
	Escreva uma função que calcule e retorne o número de anos necessários para que a população do país A
	ultrapasse ou iguale a população do país B, mantidas as taxas de crescimento.

	A função irá retornar -1 se algum dos parâmetros for  negativo ou se nunca for possível a população
	do país A ultrapassar a população de B.

	Parametros:
	pA: população do país A
	taxaA: taxa de crescimento de A em porcentagem
	pB: população do país A
	taxaB: taxa de crescimento de B em porcentagem
*/
int ultrapassagem(int popA, double taxaA, int popB, double taxaB)
{
	int anos = 0;

	if ((popA <= 0) || (popB <= 0) || (taxaA <= 0) || (taxaB <= 0))
	{
		printf("Tal operacao nao e possivel.");
		return -1;
	}
	else
	{
		while (popA != popB)
		{
			popA = popA * taxaA;
			popB = popB * taxaB;
			anos++;

			if (anos > 32000)
			{
				printf("Nao ultrapassou");
				return -1;
			}
		}
		printf("Taxa A: %.2f; Populacao A: %i; Taxa B: %.2f; Populacao B: %i; Anos: %i\n\n", taxaA, popA, taxaB, popB, anos);
		return anos;
	}
}

/*

	Esta função recebe tres numeros inteiros (inicio, fim e passo).
	Se qualquer desses numeros for negativo ou nulo a função devera
	retornar -1 (apenas como uma excecao e nao para representar o resultado
	da operacao);
	Se o valor de fim for menor do que o valor de inicio, a função tambem
	devera retornar -1 (menos um).

	Caso contrario, a função devera retornar a soma de todos os numeros
	"primos de Germain" que aparecem no intervalo. Sophie Germain foi
	uma matemática francesa nascida no século XVIII.	Um número n é "primo
	de Germain" se n é primo e 2n+1 também é primo.

	Os "primos de Germain" são chamados "primos seguros", devido a uma
	aplicação prática que ela nunca poderia ter previsto. Os principais
	métodos atuais de criptografia são baseados no fato de que, dado um
	produto pq de dois primos grandes, é difícil identificar os fatores
	p e q. Mas isso depende da escolha dos primos: por exemplo, se p é
	tal que p–1 pode ser fatorizado em primos pequenos, não é tão
	difícil quebrar a criptografia. Um jeito de evitar esse risco é usar
	p e q que sejam primos seguros. (Marcelo Vianna, Folha de São Paulo,
  01/06/22)

	Por exemplo, para inicio=0, fim=10 e passo=1, a função devera retornar 10,
	pois os "primos de Germain" são 2, 3 e 5, logo, a soma deles é 10.
	Fique à vontade para criar funções auxiliares caso julgue necessário para
	obter o resultado desta função.

	Parametros:
		inicio - Primeiro valor a participar da soma
		fim - Os valores utilizados na soma devem ser menores do que fim
		passo - Variacao aplicada a cada valor a partir do valor de inicio
*/
int somaprimosdegermain(int inicio, int fim, int passo)
{
	int soma, valor, proxPrimo, resultado, contador = inicio;
	if ((contador < 0 || fim < 0 || passo < 0) || (fim < contador))
	{
		return -1;
	}
	else
	{
		while (contador <= fim)
		{
			resultado = primo(contador);
			if (resultado)
			{
				proxPrimo = 2 * contador + 1;
				if (primo(proxPrimo))
				{
					soma += contador;
				}
			}
			contador += passo;
		}
	}
	printf("Inicio: %i; Fim: %i; Passo: %i; Resultado: %i \n\n", inicio, fim, passo, soma);
	return soma;
}
int primo(int n)
{
	int x = 2;
	if (n == 0 || n == 1)
	{
		return 0;
	}
	else
	{
		while (x < n)
		{
			if (n % x == 0)
			{
				return 0; // Retorna falso se for primo
			}
			x++;
		}
		return 1; // Retorna verdadeiro se for primo
	}
}

/*
  Considere a sequência de números: 1, -1/2, 1/3, -1/4, 1/5,...
	onde n é um número inteiro maior que zero.

	Esta função calcula, para um valor de n passado como parâmetro,
	a somatória de 1 + (-1/2) + 1/3 + (-1/4) + 1/5... + (-1)^(n+1)/n
	onde o símbolo ^ representa a operação de potenciação. Por exemplo,
	2^2 = 4.

	Note que a fórmula (-1)^(n+1)/n dá o n-ésimo elemento
	da sequência. Por exemplo, para n=1, (-1)^(1+1)/1 = 1^2/1 = 1; para
	n = 3, o terceiro elemento será (-1)^(3+1)/3 = (-1)^4/3 = 1/3.

	A função recebe como parâmetro um número inteiro e retorna a somatória
	da sequência. O valor da somatória será um número real, logo, o retorno
	dela será um double.

	Se o parâmetro de entrada representando n for menor ou igual a zero, a
	função irá	retornar -1 (apenas como uma excecao e nao para representar o resultado
	da operacao);

		Parametros:
		n - inteiro positivo

*/
double somasequencia(long n)
{
	double soma = 0;
	int i = 1;

	if (n <= 0)
	{
		return -1;
	}
	else
	{
		while (i <= n)
		{
			soma = soma + pow(-1, i + 1) / i;
			i++;
		}
		printf("Soma da sequencia para n = %ld: %f \n\n", n, soma);
		return soma;
	}
}

/*
	Esta função calcula o fatorial de um número natural n (lembre-se
  que os números naturais são inteiros maiores ou iguais a zero)

	Ela recebe um numero inteiro como parâmetro (n).
	Se este numero for menor do que zero, a função devera retornar -1.

	Caso contrario, a função devera retornar o fatorial de n, isto é, n!

	Parametro:
		n - indica o numero natural para o qual será calculado o fatorial
*/
long fatorial(int n)
{
	if (n < 0)
	{
		return -1;
	}
	else
	{
		int contador = n;
		long fatorial;
		for (fatorial = 1; contador > 1; contador--)
		{
			fatorial *= contador;
		}

		printf("Valor de n: %i; Resultado: %li\n\n", n, fatorial);
	}
}

int main()
{
	separaNumero(2345);
	separaNumero(606);
	separaNumero(-1);
	ultrapassagem(37000, 2, 400000, 1.5); // Alcança
	ultrapassagem(37000, 2, 37000, 1.5);  // Observar
	ultrapassagem(37000, 2, 400000, 1);	  // Alcança
	ultrapassagem(37000, 0.2, 400000, 1); // Não Alcaça
	ultrapassagem(37000, 2, 400000, -1);  // Alcaça
	somaprimosdegermain(0, 10, 1);
	somaprimosdegermain(1, 30, 1);
	somasequencia(5);
	somasequencia(50);
	somasequencia(1000);
	somasequencia(25000);
	somasequencia(32000);
	somasequencia(32000000);
	fatorial(-1);
	fatorial(0);
	fatorial(1);
	fatorial(2);
	fatorial(3);
	fatorial(4);
	fatorial(5);
	fatorial(6);
	fatorial(7);
	fatorial(10);
	fatorial(50);
	printf("\n\n\n\n TERMINOU \n\n\n\n\n\n");
	return 0;
}

* /
