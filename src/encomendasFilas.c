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
  free(P);
  P = NULL;
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

PNodoFila mostrarPorCliente(PNodoFila Fila, CLIENTE C)
{
	PNodoFila aux =NULL;
	while(Fila != NULL)
	{
		aux = Inserir(Fila->Elemento,aux);
		if(C.NIF == Fila->Elemento.NIF)
			MostrarEncomenda(Fila->Elemento);
		Fila = Remover(Fila);

	}
	return aux;
}

PNodoFila ConsultarEncomendas(PNodoFila Fila)
{
	PNodoFila aux =NULL;
	while(Fila != NULL)
	{
		aux = Inserir(Fila->Elemento,aux);
		MostrarEncomenda(Fila->Elemento);
		Fila = Remover(Fila);
	}
	return aux;
}


PNodoFila RemoverEncomenda(PNodoFila Fila,ENCOMENDA * e)
{
	int id,removed=0;
	PNodoFila aux=NULL;
	printf("Qual o ID da encomenda para remover?\n");
	scanf("%d",&id);
	while(Fila != NULL)
	{
		if(Fila->Elemento.ID == id)
		{
			(*e)=Fila->Elemento;
			Fila = Remover(Fila);
			removed = 1;
			
		}else
		{
			aux = Inserir(Fila->Elemento,aux);
			Fila = Remover(Fila);
		}
	}
	if(removed == 0)
	{
		printf("Esse id não existe!\n");
	}else
	{
		printf("Encomenda removida com sucesso.\n");
	}
	return aux;
}

PNodoFila guardarEncomendas(PNodoFila Fila, FILE * FP)
{
	PNodoFila aux=NULL;
	while(Fila !=NULL)
	{
		aux = Inserir(Fila->Elemento,aux);
		fwrite(&Fila->Elemento,sizeof(ENCOMENDA),1,FP);
		Fila = Remover(Fila);
	}
	return aux;
}