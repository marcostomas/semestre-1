/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   2022104 - Marcos Lordello Chaim                               **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   Marcos Paulo Tomás Ferreira                   13747950        **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0
#define TAM 150
#define TAMNOMES 200

#define COMPUTACAO 0
#define LITERATURA 1
#define CIENCIAS 2
#define ARTES 3
#define GERAL 4

typedef int bool;

typedef struct
{
	char nome[TAMNOMES];
	char primeiro_autor[TAMNOMES];
	char demais_autores[TAMNOMES];
	bool emprestado;
	int noEmprestimos;
	char nomeDoEmprestador[TAMNOMES];
	char editora[TAMNOMES];
	int area;
	int anopub;
} Livro;

typedef struct
{
	Livro *livros[TAM];
	int posLivre;
} Biblioteca;

/********************** FUNCOES PARA CRIAR LIVROS ******/

/* Funcao para a criacao de um novo Livro.
   A funcao preenche todos os valores de seus campos e retorna esse novo Livro.
*/
Livro *novoLivro(char *nome, char *nAutorPrin, char *nOutrosAutores, char *emprestador, int nArea,
				 char *nEditora, int nAnoPub)
{
	// printf("Parametros: %s, %s, %s, %s, %d, %s, %d\n", nome, nAutorPrin, nOutrosAutores, emprestador, nArea, nEditora, nAnoPub);
	Livro *novo = (Livro *)malloc(sizeof(Livro));

	if (novo == NULL)
		return NULL; // Nao consegui alocar memoria para o registro Livro. Vou cair fora!

	strncpy(novo->nome, nome, TAMNOMES - 1);
	strncpy(novo->primeiro_autor, nAutorPrin, TAMNOMES - 1);
	strncpy(novo->demais_autores, nOutrosAutores, TAMNOMES - 1);

	novo->emprestado = false;
	novo->noEmprestimos = 0;

	strncpy(novo->nomeDoEmprestador, emprestador, TAMNOMES - 1);
	strncpy(novo->editora, nEditora, TAMNOMES - 1);

	novo->area = nArea;
	novo->anopub = nAnoPub;

	return novo;
}

/********************** FUNCOES DOS alunos *********************************/

/* Funcao para imprimir informacoes  sobre o livro l1 (passado como parametro)
Veja na descricao do EP2 como essas informacoes devem ser impressas
*/
void imprimirDados(Livro *l1)
{
	printf("Nome: %s \nAutor: %s \nAutores Secundarios: %s \nEditora: %s \nArea: %s \nAno Publicacao: %i \nNumero de Emprestimos: %i \n", l1->nome, l1->primeiro_autor, l1->demais_autores, l1->editora, l1->area, l1->anopub, l1->noEmprestimos);

	if (l1->emprestado)
	{
		printf("Emprestado? Sim");
	}
	else
	{
		printf("Emprestado? Nao");
	}
}

int menorEl_NoEmprestimos(Livro *biblioteca, int tam, int inicio)
{
	int i, posMenor;
	posMenor = -1;
	if ((inicio >= 0) && (inicio < tam))
	{
		posMenor = inicio;
		for (i = inicio + 1; i < tam; i++)
			if (biblioteca->noEmprestimos[i] > biblioteca->noEmprestimos[posMenor])
				posMenor = i;
	}
	return (posMenor);
}

void OrdenacaoPorSelecaoEmprestimos(Livro *bib, int tam)
{
	int i, posMenor, aux;
	for (i = 0; i < tam - 1; i++)
	{
		posMenor = menorEl_NoEmprestimos(bib, tam, i);
		aux = bib[i];
		bib[i] = bib[posMenor];
		bib[posMenor] = aux;
	}
}

/*
A funcao abaixo recebe como parametro um ponteiro para a biblioteca e ordena-a por
numero de emprestimos.
*/
void ordenaBibliotecaPorNumeroEmprestimos(Biblioteca *bib)
{
	OrdenacaoPorSelecaoEmprestimos(bib, 150);
}

int menorEl_Nome(Livro *biblioteca, int tam, int inicio)
{
	int i, posMenor;
	posMenor = -1;
	if ((inicio >= 0) && (inicio < tam))
	{
		posMenor = inicio;
		for (i = inicio + 1; i < tam; i++)
			if (biblioteca->nome[i] < biblioteca->nome[posMenor])
				posMenor = i;
	}
	return (posMenor);
}

void OrdenacaoPorSelecaoNome(Livro *bib, int tam)
{
	int i, posMenor, aux;
	for (i = 0; i < tam - 1; i++)
	{
		posMenor = menorEl_Nome(bib, tam, i);
		aux = bib[i];
		bib[i] = bib[posMenor];
		bib[posMenor] = aux;
	}
}

/*
A funcao abaixo recebe como parametro um ponteiro para a biblioteca e ordena-a por
nome do livro em ordem lexicografica.
*/
void ordenaBibliotecaNomeLivro(Biblioteca *bib)
{
	OrdenacaoPorSelecaoNome(bib, 150);
}

// O que vem antes desse comentário já está feito. Falta testar! A fazer:

/*
A funcao abaixo busca um livro na biblioteca pelo nome do livro. Ela retorna
o ponteiro para o livro, se existir, e NULL, se nao existir, na biblioteca.
*/
Livro *buscaLivro(Biblioteca *bib, char *nNomeLivro)
{
	/* Insira seu codigo aqui! */
	return NULL; // Codigo inserido so para permitir a compilacao desse template.
}

/*
A funcao abaixo insere um livro na biblioteca. Ela recebe como parametros os
ponteiros para a biblioteca e o livro. O livro deve ser criado antes. Se a
biblioteca ja estiver lotada, deve ser seguida especificacao contida na
descricao do EP2 para tratar essa situacao.
*/
void insereLivro(Biblioteca *bib, Livro *l)
{
	/* Insira seu codigo aqui! */
}

/*
A função emprestaLivro procura o livro pelo nome na biblioteca e empresta
para o nEmprestador. A função retorna o ponteiro para o livro emprestador
se existir; caso contrário, volta NULL. A funcao retorna NULL tambem se
o livro ja estiver emprestado. Uma vez emprestado o livro,  seu campo
emprestado deve ser igual a true e seu campo noEmprestimos deve ser incrementado.
*/
Livro *emprestaLivro(Biblioteca *bib, char *nNomeLivro, char *nEmprestador)
{
	/* Insira seu codigo aqui! */
	return NULL; // Codigo inserido so para permitir a compilacao desse template.
}

/*
A função devolveLivro procura o livro pelo nome na biblioteca e atualiza
o nEmprestador com o string "" e o campo emprestado com false.
A função retorna o ponteiro para o livro devolvido
se existir; caso contrário, volta NULL. A funcao nao altera o
valor do campo  noEmprestimos.
*/
Livro *devolveLivro(Biblioteca *bib, char *nNomeLivro)
{
	/* Insira seu codigo aqui! */

	return NULL; // Codigo inserido so para permitir a compilacao desse template.
}

/*
 Esta funcao devolve o numero de livros na biblioteca
*/
int tamanho(Biblioteca *bib)
{
	return 0; // Codigo inserido so para permitir a compilacao desse template.
}

// O que vem depois desse comentário já está feito. Falta testar!
/*
Esta funcao imprime o conteudo da biblioteca ordenada por numero de noEmprestimos
de cada livro. Os mais emprestados primeiro.
*/
void imprimeBibliotecaPorNumeroEmprestimos(Biblioteca *bib)
{
	int i;
	ordenaBibliotecaPorNumeroEmprestimos(bib);
	for (i = 0; i < 150; i++)
	{
		imprimirDados(bib[i]);
	}
}

/*
Esta funcao imprime o conteudo da biblioteca ordenada pelo nome de cada livro em
ordem lexicografica.
*/
void imprimirBibliotecaOrdenadaNomeLivro(Biblioteca *bib)
{
	int i;
	ordenaBibliotecaNomeLivro(bib);
	for (i = 0; i < 150; i++)
	{
		imprimirDados(bib[i]);
	}
}

int main()
{
	Biblioteca *bib = (Biblioteca *)malloc(sizeof(Livro)); //"Instanciando" biblioteca
	return 0;
}