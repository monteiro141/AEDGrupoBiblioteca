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

void operacao5(PNodoFila ENCOMENDA);