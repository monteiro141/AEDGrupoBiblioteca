#include <stdio.h>
#include "encomendasFilas.h"

//-----------------------------------------------------------
//Funcoes auxiliares
PNodoFila CriarNodoFila (ENCOMENDA X){
  PNodoFila P;
  P = (PNodoFila) malloc(sizeof(struct NodoFila));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

int FilaVazia (PNodoFila Fila){
  if (Fila == NULL)
    return 1;
  else
    return 0;
}

PNodoFila CriarFila (){
  PNodoFila P;
  P = NULL;
  return P;
}

PNodoFila Remover (PNodoFila Fila){
  PNodoFila P;
  P = Fila;
  Fila = Fila->Prox;
  P = LibertarNodoFila(P);
  return Fila;
}

//-----------------------------------------------------------
//-----------------------------------------------------------
PNodoFila Inserir (ENCOMENDA X, PNodoFila Fila)
{
  	PNodoFila Novo, PAnt;
	Novo = CriarNodoFila(X);
	if (Novo == NULL)
		return Fila;
	if (FilaVazia(Fila))
	{
		Fila = Novo;
		return Fila;
	}
	PAnt = Fila;
	while(PAnt->Prox != NULL)
		PAnt = PAnt->Prox;
	PAnt->Prox = Novo;
	return Fila;
}

PNodoFila RemoverEncomendaDadoNIF(PNodoFila Fila)
{
	int flag=0; //0->Nao removeu; 1->Removeu;
	long long int NIF=0;
	PNodoFila Aux = NULL;
	printf("Insira o 'NIF' a que quer remover as encomendas: \n");
	scanf("%lld",NIF);
	while(Fila != NULL)
	{
		if (Fila->Elemento.NIF == NIF)
		{
			Remover(Fila);
			flag=1;
		}
		else
		{
			Aux = Inserir(Fila->Elemento,Aux);
			Fila = Fila -> Prox;
		}
	}
	if (flag == 0)
		printf("Nenhuma correspondência encontrada!\n");
	return Aux;
}