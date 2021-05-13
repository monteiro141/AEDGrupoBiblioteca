/*---------------------------Data---------------------------*/
/*
Data: Contêm apenas Dia, Mes e Ano.
*/
#ifndef OPERACOESPRIMARIAS_H
#define OPERACOESPRIMARIAS_H
#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    int Dia;
    int Mes;
    int ano;
} DATADMA;

typedef struct LIVRO
{
    long long int ISBN;
    char Titulo[100];
    char Idioma[100];
    char PrimeiroAutor[100];
    char SegundoAutor[100];
    char Editora[100];
    int AnoPublicacao;
    char AreaCientifica[100];
    float Preco;
    int QuantidadeStock;
} LIVRO;

typedef struct ENCOMENDA
{
    int ID;
    long long int ISBN;
    long long int NIF;
    DATADMA Encomenda;
    DATADMA Concluida;
    int Quantidade;
    float PrecoTotal;
}ENCOMENDA;

typedef struct CLIENTE
{
    long long int NIF;
    char Nome[100];
    char Morada[100];
    long long int Telefone;
    ENCOMENDA ListaDeCompras[100];
    int numeroEncomendas;
}CLIENTE;


struct NodoFila {
  ENCOMENDA Elemento;
  struct NodoFila *Prox;
};

typedef struct NodoFila *PNodoFila;

struct NodoAB {
  LIVRO Elemento;
  struct NodoAB *Esquerda;
  struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;

struct Nodo {
  CLIENTE Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;

/*---------------------------Livro + Funções---------------------------*/
/*
Livro:ISBN, Título, Idioma, Primeiro Autor, Segundo Autor, Editora, Ano de Publicação, Área Científica (Matemática, Física, Química,
        Programação, Informática, Processamento Digital, Sistemas Digitais, Base de Dados, ...), Preço (euros) e Quantidade em “stock”.
Funções:MostrarLivro(Recebe um Livro X e mostra os atributos todos do livro, não devolve)
        CriarLivro(Cria um livro modo random e devolve um livro)
        CompararLivros(Recebe livro X e Y, devolve 0 se forem iguais, -1 se x < y e 1 se x > y).
*/

void MostrarLivro (LIVRO X);
LIVRO CriarLivro ();
int CompararLivros (LIVRO X, LIVRO Y);


/*---------------------------Encomenda + funções---------------------------*/
/*
Encomenda:Livro (ISBN), Cliente (NIF), Data de encomenda/compra/venda, Número de unidades encomendadas e Preço total.
Funções:MostrarEncomenda(Recebe uma Encomenda X e mostra os atributos todos da Encomenda, não devolve)
        CriarEncomenda(Cria uma Encomenda modo random e devolve uma Encomenda)
        CompararEncomendas(Recebe Encomenda X e Y, devolve 0 se forem iguais, -1 se x < y e 1 se x > y).
*/
PNodoFila Inserir (ENCOMENDA X, PNodoFila Fila);
PNodoFila Remover (PNodoFila Fila);
PNodoFila mostrarPorCliente(PNodoFila Fila, CLIENTE C);
void MostrarEncomenda (ENCOMENDA E);
int CriarEncomenda (CLIENTE C, LIVRO L,ENCOMENDA * E, PNodoFila * encomendas);
int CompararEncomendas (ENCOMENDA X, ENCOMENDA Y);


/*---------------------------Cliente + funções---------------------------*/
/*
Encomenda:NIF, Nome, Morada, Telefone e Lista de compras efetuadas.
Funções:MostrarCliente(Recebe um Cliente X e mostra os atributos todos do Cliente, não devolve)
        CriarCliente(Cria um Cliente modo random e devolve um Cliente)
        CompararClientes(Recebe Cliente X e Y, devolve 0 se forem iguais, -1 se x < y e 1 se x > y).
*/

PNodoFila MostrarCliente (CLIENTE C,PNodoFila Fila);
CLIENTE CriarCliente();
int CompararClientes (CLIENTE X, CLIENTE Y);

#endif