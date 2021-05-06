#include <stdio.h>
#include <string.h>
#include "encomendasFilas.h"

//Quantos livros foram vendidos num dado período de tempo (mês e ano)
PNodoFila operacao1(PNodoFila Encomendas);

//Determinar a data da última compra/venda de um dado livro
PNodoFila operacao2(PNodoFila Encomendas);

//Determinar quantos livros um dado cliente já comprou
PNodoFila operacao3(PNodoFila Encomendas);

//Mostrar os K livros mais recentes de uma dada Área Científica
void bubbleSort4(LIVRO ** arr, int n);
void operacao4Aux(PNodoAB Livros, LIVRO ** kLivros,int * quantidade, char * areaC);
void operacao4(PNodoAB Livros);


//Mostrar os K livros mais vendidos num dado período (mês e ano);
typedef struct operacao5Counter
{
    long long int ISBN;
    int qtd;
}operacao5Counter;
void bubbleSort5(operacao5Counter ** arr, int n);
PNodoFila operacao5Aux(PNodoFila ENCOMENDA,int mI,int mF,int aI,int aF,operacao5Counter ** kLivros,int * quantidade);
PNodoFila operacao5(PNodoFila ENCOMENDA,PNodoAB LIVROS);


//6 Determinar a Área Científica com mais livros
typedef struct operacao6counter
{   char AreaCientifica[100];
    int qtd;
} operacao6counter;
void bubbleSort6(operacao6counter ** arr, int n);
void operacao6Aux(PNodoAB LIVROS, operacao6counter ** livrosAC, int * quantidade);
void operacao6(PNodoAB LIVROS);


//Determinar qual o Cliente com mais livros comprados;
typedef struct operacao7counter
{   long long int NIF;
    int qtdLivros;
} operacao7counter;
void bubbleSort7(operacao7counter ** arr, int n);
PNodoFila operacao7Aux(PNodoFila ENCOMENDAS,operacao7counter ** clientes,int * quantidade);
PNodoFila operacao7(PNodoFila ENCOMENDAS, PNodo L);

//Mostrar os Clientes por ordem decrescente do número de compras
typedef struct operacao8cliente
{
    long long int NIF;
    char Nome[100];
    int numeroCompras;
}operacao8cliente;

void operacao8(PNodo listaClientes);

//Determinar o Ano com mais publicações
typedef struct
{
    int ano;
    int qtd;
}operacao9counter;

void operacao9Aux(PNodoAB LIVROS, operacao9counter ** livrosAnoPub,int * quantidade);
void operacao9(PNodoAB LIVROS);


//Calcular o cliente que mais gastou num dado período (mês e ano)
PNodoFila operacao10(PNodo Clientes, PNodoFila Encomendas);

//Determinar o desperdício de memória.
size_t operacao11Aux(PNodoAB LIVROS);
PNodoFila operacao11(PNodoFila ENCOMENDAS, PNodo CLIENTES, PNodoAB LIVROS);


// Qual a encomenda mais antiga.
PNodoFila operacao12 (PNodoFila Encomendas);
// O cliente com mais encomendas concluidas.
void operacao13(PNodo Clientes);
//Dado um livro, quais foram os clientes que o compraram.
PNodoFila operacao14(PNodoAB Livros, PNodo Clientes, PNodoFila Encomendas);
//Quantos clientes existem no programa.
PNodoFila operacao15 (PNodo Clientes, PNodoFila Encomendas);