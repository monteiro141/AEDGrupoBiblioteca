#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "clientesListasLigadas.h"

PNodo Criar (){
  PNodo L;
  L = NULL;
  return L;
}

//Funcoes Auxiliares

int Pesquisar (CLIENTE C, PNodo L){ 
  	while (L != NULL && CompararElementos(L->Elemento, C) != 0)
    	L = L->Prox; 
  	if (L == NULL) return 0; 
  	else return 1;
}

PNodo ProcurarAnteriorNIF (long long int NIF, PNodo L){
  PNodo  Ant = NULL; 
  while (L != NULL && (L->Elemento->NIF == NIF)){
    Ant = L;
    L = L->Prox;
  } 
  return Ant;
}

PNodo ProcurarAnteriorNome (char* Nome, PNodo L){
  PNodo  Ant = NULL; 
  while (L != NULL && strstr(L->Elemento->Nome, Nome)){
    Ant = L;
    L = L->Prox;
  } 
  return Ant;
}

PNodo ProcurarAnteriorMorada (char* Morada, PNodo L){
  PNodo  Ant = NULL; 
  while (L != NULL && strstr(L->Elemento->Morada, Morada)){
    Ant = L;
    L = L->Prox;
  } 
  return Ant;
}

void ConsultarClientesPorNIF(long long int NIF, PNodo L)
{
	PNodo aux = ProcurarAnteriorNIF(NIF, L);
	MostrarElemento(aux->Elemento)
}

void ConsultarClientesPorNome(char* Nome, PNodo L)
{
	PNodo aux = ProcurarAnteriorNome(Nome, L);
	MostrarElemento(aux->Elemento)
}

void ConsultarClientesPorMorada(char* Morada, PNodo L)
{
	PNodo aux = ProcurarAnteriorMorada(Morada, L);
	MostrarElemento(aux->Elemento)
}

//----------------------------------------------
//Inserir
PNodo InserirInicio (CLIENTE C, PNodo L)
{
  PNodo P = CriarNodo(C);
  if (P == NULL)
    return L;
  P->Prox = L;
  L = P;
  return L;
}

//Remover com NIF
PNodo RemoverComNIF (long long int NIF, PNodo L)
{ 
  PNodo P, PAnt;
  PAnt = ProcurarAnteriorNIF(NIF, L); 
  if (PAnt == NULL){   // remover elemento do início de L
    P = L;
    L = L->Prox;
  }
  else{
    P = PAnt->Prox;
    PAnt->Prox = P->Prox; // ou (PAnt->Prox)->Prox
  } 
  LibertarNodo(P); 
  return  L;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!
//Alterar com NIF - POR FAZER
//!!!!!!!!!!!!!!!!!!!!!!!!!!!
PNodo AlterarComNIF (long long int NIF, PNodo L)
{
	PNodo P, PAnt;
  	PAnt = ProcurarAnteriorNIF(NIF, L); //se existir, pedir o que quer alterar;
}

//Consultar por
void ConsultarClientesPor(int n, PNodo L)
{
	//fazer menus para mostrar o que cada numero significa
	printf("Escolha uma das seguintes opcões:\n", );
	printf("1 - NIF\n");
	printf("2 - Nome\n");
	printf("3 - Morada\n");
	printf("Para sair insira um número que seja diferente dos números acima.\n");
	switch(n)
	{
		//NIF
		case 1:
		long long int NIF = 0
		printf("Insira um 'NIF' válido: ");
		scanf("%i", NIF);
		printf("\n");
		ConsultarPorNIF(NIF,PNodo L);
		break;

		//Nome
		case 2:
		char Nome[100];
		printf("Insira um 'Nome' válido: ");
		scanf("%s", Nome);
		printf("\n");
		ConsultarPorNome(Nome,PNodo L);
		break;

		//Morada
		case 3:
		char Morada[100];
		printf("Insira uma 'Morada' válida: ");
		scanf("%s", Morada);
		printf("\n");
		ConsultarPorMorada(Morada,PNodo L);
		break;

		default:
		printf("Operação inválida, por favor insira um número válido.\n");
	}
}