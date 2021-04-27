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
  while (Aux != NULL && Aux->Elemento->NIF != NIF) Aux = Aux -> Prox;
  if(Aux->Elemento->NIF != NIF) return NULL;
  else return Aux;
}

PNodo ProcurarNome (char* Nome, PNodo L)
{
  PNodo  Aux = L; 
  while (Aux != NULL && strstr(Aux->Elemento->Nome, Nome)) Aux = Aux -> Prox;
  if(strcmp(L->Elemento->Nome, Nome) != 0) return NULL;
  else return Aux;
}

PNodo ProcurarMorada (char* Morada, PNodo L)
{
  PNodo  Aux = L; 
  while (Aux != NULL && strstr(Aux->Elemento->Morada, Morada)) Aux = Aux -> Prox;
  if(strcmp(L->Elemento->Morada, Morada) !=0) return NULL;
  else return Aux;
}

PNodo ProcurarnTelefone (long long int nTele, PNodo L)
{
  PNodo  Aux = L; 
  while (Aux != NULL && Aux->Elemento->Telefone != nTele) Aux = Aux -> Prox;
  if(Aux->Elemento->Telefone != nTele) return NULL;
  else return Aux;
}

void ConsultarClientesPorNIF(long long int NIF, PNodo L)
{
	PNodo aux = ProcurarNIF(NIF, L);
	if (aux == NULL) printf("Cliente não encontrado, por favor verifique se o 'NIF' foi inserido corretamente!\n");
	else MostrarElemento(aux->Elemento)
}

void ConsultarClientesPorNome(char* Nome, PNodo L)
{
	PNodo aux = ProcurarNome(Nome, L);
	if (aux == NULL) printf("Cliente não encontrado, por favor verifique se o 'Nome' foi inserido corretamente!\n");
	else MostrarElemento(aux->Elemento)
}

void ConsultarClientesPorMorada(char* Morada, PNodo L)
{
	PNodo aux = ProcurarMorada(Morada, L);
	if (aux == NULL) printf("Cliente não encontrado, por favor verifique se a 'Morada' foi inserido corretamente!\n");
	else MostrarElemento(aux->Elemento)
}

void ConsultarClientesPornTelefone(long long int nTele, PNodo L)
{
	PNodo aux = ProcurarnTelefone(nTele, L);
	if (aux == NULL) printf("Cliente não encontrado, por favor verifique se o 'Número de telefone' foi inserido corretamente!\n");
	else MostrarElemento(aux->Elemento)
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
  LibertarNodo(P); 
  return  L;
}

PNodo AlterarComNIF (long long int NIF, PNodo L)
{
	PNodo P = ProcurarAnteriorNIF(NIF, L); //se existir, pedir o que quer alterar;
  	if (P == NULL) printf("Erro: esse 'NIF' não está associado a nenhum Cliente, por favor verifique se inseriu o 'NIF' corretamente.\n");
  	else
  	{
  		printf("Insira o que pretende alterar:\n");
  		printf("1 - Nome\n");
		printf("2 - Morada\n");
		printf("3 - Número de telefone\n");
		printf("Para sair insira um número que seja diferente dos números acima.\n");
		switch(n)
		{
			//Nome
			case 1:
			char Nome[100];
			printf("Insira um 'Nome' válido: ");
			scanf("%s", Nome);
			P -> Elemento -> Nome = Nome;
			break;

			//Morada
			case 2:
			char Morada[100];
			printf("Insira uma 'Morada' válida: ");
			scanf("%s", Morada);
			P -> Elemento -> Morada = Morada;
			break;

			case 3:
			long long int nTelefone = 0
			printf("Insira um 'Número de telefone' válido: ");
			scanf("%i", nTelefone);
			P -> Elemento -> Telefone = nTelefone;
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
void ConsultarClientesPor(int n, PNodo L)
{
	printf("Escolha uma das seguintes opcões:\n", );
	printf("1 - NIF\n");
	printf("2 - Nome\n");
	printf("3 - Morada\n");
	printf("4 - Número de telefone\n");
	printf("Para sair insira um número que seja diferente dos números acima.\n");
	switch(n)
	{
		//NIF
		case 1:
		long long int NIF = 0
		printf("Insira um 'NIF' válido: ");
		scanf("%i", NIF);
		printf("-----------------------------\n");
		ConsultarClientesPorNIF(NIF,PNodo L);
		break;

		//Nome
		case 2:
		char Nome[100];
		printf("Insira um 'Nome' válido: ");
		scanf("%s", Nome);
		printf("-----------------------------\n");
		ConsultarClientesPorNome(Nome,PNodo L);
		break;

		//Morada
		case 3:
		char Morada[100];
		printf("Insira uma 'Morada' válida: ");
		scanf("%s", Morada);
		printf("-----------------------------\n");
		ConsultarClientesPorMorada(Morada,PNodo L);
		break;

		case 4:
		long long int nTelefone = 0
		printf("Insira um 'Número de telefone' válido: ");
		scanf("%i", nTelefone);
		printf("-----------------------------\n");
		ConsultarClientesPornTelefone(nTelefone,PNodo L);
		break;

		default:
		printf("Operação inválida, por favor insira um número válido.\n");
	}
}