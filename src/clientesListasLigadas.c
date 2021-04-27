#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "clientesListasLigadas.h"

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//Funcoes Auxiliares
PNodo Criar ()
{
  PNodo L;
  L = NULL;
  return L;
}

int Pesquisar (CLIENTE C, PNodo L)
{ 
  	while (L != NULL && CompararElementos(L->Elemento, C) != 0)
    	L = L->Prox; 
  	if (L == NULL) return 0; 
  	else return 1;
}

PNodo ProcurarNIF (long long int NIF, PNodo L)
{
  PNodo  Aux = L; 
  while (Aux != NULL && Aux->Elemento.NIF != NIF) 
  	Aux = Aux -> Prox;

  if(Aux->Elemento.NIF != NIF) 
  	return NULL;
  else 
  	return Aux;
}

PNodo ProcurarAnteriorNIF (long long int NIF, PNodo L){
  PNodo  Ant = NULL; 
  while (L != NULL && L->Elemento.NIF != NIF){
    Ant = L;
    L = L->Prox;
  } 

  if(L->Elemento.NIF != NIF) 
  	return NULL;
  else
  	return Ant;
}

PNodo ProcurarNome (char* Nome, PNodo L)
{
  PNodo  Aux = L; 
  while (Aux != NULL && strstr(Aux->Elemento.Nome, Nome)) Aux = Aux -> Prox;
  if(strcmp(L->Elemento.Nome, Nome) != 0) return NULL;
  else return Aux;
}

PNodo ProcurarMorada (char* Morada, PNodo L)
{
  PNodo  Aux = L; 
  while (Aux != NULL && strstr(Aux->Elemento.Morada, Morada)) Aux = Aux -> Prox;
  if(strcmp(L->Elemento.Morada, Morada) !=0) return NULL;
  else return Aux;
}

PNodo ProcurarnTelefone (long long int nTele, PNodo L)
{
  PNodo  Aux = L; 
  while (Aux != NULL && Aux->Elemento.Telefone != nTele) Aux = Aux -> Prox;
  if(Aux->Elemento.Telefone != nTele) return NULL;
  else return Aux;
}

void ConsultarClientesPorNIF(long long int NIF, PNodo L)
{
	PNodo aux = ProcurarNIF(NIF, L);
	if (aux == NULL) printf("Cliente não encontrado, por favor verifique se o 'NIF' foi inserido corretamente!\n");
	else MostrarElemento(aux->Elemento);
}

void ConsultarClientesPorNome(char* Nome, PNodo L)
{
	PNodo aux = ProcurarNome(Nome, L);
	if (aux == NULL) printf("Cliente não encontrado, por favor verifique se o 'Nome' foi inserido corretamente!\n");
	else MostrarElemento(aux->Elemento);
}

void ConsultarClientesPorMorada(char* Morada, PNodo L)
{
	PNodo aux = ProcurarMorada(Morada, L);
	if (aux == NULL) printf("Cliente não encontrado, por favor verifique se a 'Morada' foi inserido corretamente!\n");
	else MostrarElemento(aux->Elemento);
}

void ConsultarClientesPornTelefone(long long int nTele, PNodo L)
{
	PNodo aux = ProcurarnTelefone(nTele, L);
	if (aux == NULL) printf("Cliente não encontrado, por favor verifique se o 'Número de telefone' foi inserido corretamente!\n");
	else MostrarElemento(aux->Elemento);
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

PNodo InserirInicio (CLIENTE C, PNodo L)
{
  PNodo P = CriarNodo(C);
  if (P == NULL)
    return L;
  P->Prox = L;
  L = P;
  return L;
}

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
  free(P);
  P = NULL; 
  return  L;
}

PNodo AlterarComNIF (PNodo L)
{
	long long int NIF;
	printf("Qual é o NIF?\n");
	scanf("%lld",&NIF);
	int n;
	char Nome[100]={};
	char Morada[100]={};
	long long int nTelefone = 0;
	PNodo P = ProcurarNIF(NIF, L); //se existir, pedir o que quer alterar;
  	if (P == NULL) printf("Erro: esse 'NIF' não está associado a nenhum Cliente, por favor verifique se inseriu o 'NIF' corretamente.\n");
  	
	else
  	{
  		printf("Insira o que pretende alterar:\n");
  		printf("1 - Nome\n");
		printf("2 - Morada\n");
		printf("3 - Número de telefone\n");
		printf("Para sair insira um número que seja diferente dos números acima.\n");
		scanf("%d",&n);
		switch(n)
		{
			//Nome
			case 1:
			printf("Insira um 'Nome' válido: ");
			scanf("\n%[^\n]s",Nome);
			strcpy(P->Elemento.Nome,Nome);
			break;

			//Morada
			case 2:
			printf("Insira uma 'Morada' válida: ");
			scanf("\n%[^\n]s",Morada);
			strcpy(P->Elemento.Morada,Morada);
			break;

			case 3:
			printf("Insira um 'Número de telefone' válido: ");
			scanf("%lld", nTelefone);
			P->Elemento.Telefone = nTelefone;
			break;
			default:
			printf("Operação inválida, por favor insira um número válido.\n");
		}
		printf("\n");
		printf("Mudança feita com sucesso.\n");
  	}

  	return L = InserirInicio(P->Elemento, L);
}

//Consultar por
void ConsultarClientesPor(PNodo L)
{
	int n;
	long long int NIF = 0;
	char Nome[100]={};
	char Morada[100]={};
	long long int nTelefone = 0;
	printf("Escolha uma das seguintes opcões:\n");
	printf("1 - NIF\n");
	printf("2 - Nome\n");
	printf("3 - Morada\n");
	printf("4 - Número de telefone\n");
	printf("Para sair insira um número que seja diferente dos números acima.\n");
	scanf("%d",&n);
	switch(n)
	{
		//NIF
		case 1:
		printf("Insira um 'NIF' válido: ");
		scanf("%lld", NIF);
		printf("-----------------------------\n");
		ConsultarClientesPorNIF(NIF, L);
		break;

		//Nome
		case 2:
		printf("Insira um 'Nome' válido: ");
		scanf("\n%[^\n]s",Nome);
		printf("-----------------------------\n");
		ConsultarClientesPorNome(Nome,L);
		break;

		//Morada
		case 3:
		printf("Insira uma 'Morada' válida: ");
		scanf("\n%[^\n]s",Morada);
		printf("-----------------------------\n");
		ConsultarClientesPorMorada(Morada, L);
		break;

		case 4:
		printf("Insira um 'Número de telefone' válido: ");
		scanf("%lld", nTelefone);
		printf("-----------------------------\n");
		ConsultarClientesPornTelefone(nTelefone,L);
		break;

		default:
		printf("Operação inválida, por favor insira um número válido.\n");
	}
}

void guarderClientes(PNodo L, FILE * FP)
{
	while(L!=NULL)
	{
		fwrite(&L->Elemento,sizeof(CLIENTE),1,FP);
		L = L->Prox;
	}
}