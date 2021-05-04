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

typedef struct operacao5Counter
{
    long long int ISBN;
    int qtd;
}operacao5Counter;


//Mostrar os K livros mais vendidos num dado período (mês e ano);
void bubbleSort5(operacao5Counter ** arr, int n);
PNodoFila operacao5Aux(PNodoFila ENCOMENDA,int mI,int mF,int aI,int aF,operacao5Counter ** kLivros,int * quantidade);
PNodoFila operacao5(PNodoFila ENCOMENDA,PNodoAB LIVROS);


typedef struct operacao6counter
{   char AreaCientifica[100];
    int qtd;
} operacao6counter;
//Determinar a Área Científica com mais livros
void bubbleSort6(operacao6counter ** arr, int n);
void operacao6Aux(PNodoAB LIVROS, operacao6counter ** livrosAC, int * quantidade);
void operacao6(PNodoAB LIVROS);
