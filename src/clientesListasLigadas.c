#include <stdlib.h>
#include <string.h>
#include "clientesListasLigadas.h"
#include <stdio.h>

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//Funcoes Auxiliares
PNodo Criar ()
{
  PNodo L;
  L = NULL;
  return L;
}

PNodo CriarNodo (CLIENTE X){
  PNodo P;
  P = (PNodo) malloc(sizeof(struct Nodo));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

int Pesquisar (CLIENTE C, PNodo L)
{ 
  	while (L != NULL && CompararClientes(L->Elemento, C) != 0)
    	L = L->Prox; 
  	if (L == NULL) return 0; 
  	else return 1;
}

int ProcurarNIF (long long int NIF, PNodo L,CLIENTE * C)
{
  PNodo  Aux = L; 
  while (Aux != NULL) 
  {
	if(Aux->Elemento.NIF == NIF)
	{
		(*C) = Aux->Elemento;
		return 0;
	}
	Aux = Aux->Prox;
  }
	return 1;
}

PNodo ProcurarAnteriorNIF (long long int NIF, PNodo L){
  PNodo  Ant = NULL; 
  while (L != NULL && L->Elemento.NIF != NIF){
    Ant = L;
    L = L->Prox;
  } 
  	return Ant;
}
//Fixar isto depois de jantar
int ProcurarNome (char* Nome, PNodo L,PNodoFila Fila)
{
  PNodo  Aux = L; 
  int check=0;
  while (Aux != NULL)
  {
	  if(strstr(Aux->Elemento.Nome, Nome)!=NULL)
	  {
		  Fila = MostrarCliente(Aux->Elemento,Fila);
		  check=1;
	  }
	  Aux = Aux -> Prox;
  } 
  	
  return check;
}

int ProcurarMorada (char* Morada, PNodo L,PNodoFila Fila)
{
  PNodo  Aux = L; 
  int check=0;
  while (Aux != NULL)
  {
	  if(strstr(Aux->Elemento.Morada, Morada)!=NULL)
	  {
		  Fila =  MostrarCliente(Aux->Elemento,Fila);
		  check=1;
	  }
	  Aux = Aux -> Prox;
  } 
  	
  return check;
}

int ProcurarnTelefone (long long int nTele, PNodo L, PNodoFila Fila)
{
  PNodo  Aux = L; 
  int check=0;
  while (Aux != NULL)
  {
	  if(Aux->Elemento.Telefone == nTele)
	  {
		  Fila =  MostrarCliente(Aux->Elemento,Fila);;
		  check=1;
	  }
	  Aux = Aux -> Prox;
  } 
  	
  return check;
}

PNodoFila ConsultarClientesPorNIF(long long int NIF, PNodo L,PNodoFila Fila)
{
	CLIENTE C;
	if (ProcurarNIF(NIF, L , &C)==1) 
		printf("Cliente não encontrado, por favor verifique se o 'NIF' foi inserido corretamente!\n");
	else 
		Fila = MostrarCliente(C,Fila);
	return Fila;
}

PNodoFila ConsultarClientesPorNome(char* Nome, PNodo L,PNodoFila Fila)
{
	if (ProcurarNome(Nome, L,Fila)==0) 
		printf("Cliente não encontrado, por favor verifique se o 'Nome' foi inserido corretamente!\n");
	return Fila;
}

PNodoFila ConsultarClientesPorMorada(char* Morada, PNodo L,PNodoFila Fila)
{
	
	if (ProcurarMorada(Morada, L,Fila)==0) 
		printf("Cliente não encontrado, por favor verifique se a 'Morada' foi inserido corretamente!\n");
	return Fila;
}

PNodoFila ConsultarClientesPornTelefone(long long int nTele, PNodo L,PNodoFila Fila)
{
	if (ProcurarnTelefone(nTele, L,Fila)==0) 
		printf("Cliente não encontrado, por favor verifique se o 'Número de telefone' foi inserido corretamente!\n");
	return Fila;
}

PNodoFila ConsultarClientesTodos(PNodo L, PNodoFila Fila)
{
	PNodo aux = L;
	while(aux != NULL)
	{
		Fila = MostrarCliente(aux->Elemento,Fila);
		aux = aux->Prox;
	}
	return Fila;
}
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------

PNodo InserirInicio (CLIENTE C, PNodo L)
{
	if(PesquisarRec(C,L)==0)
	{
		PNodo P = CriarNodo(C);
		if (P == NULL)
			return L;
		P->Prox = L;
		L = P;
	}else
		printf("Já existe cliente com esse NIF.\n");
	return L;
}

PNodo AtualizarCliente(CLIENTE C, CLIENTE X, PNodo L)
{
	PNodo aux = L;
	while(aux!= NULL)
	{
		if(CompararClientes(aux->Elemento,C)==0)
		{
			aux->Elemento = X;
			return L;
		}
		aux = aux->Prox;
	}
	return L;
}

CLIENTE DevolveCliente(CLIENTE C, PNodo L)
{
	PNodo aux = L;
	CLIENTE dummy;
	dummy.NIF=-1;
	while(aux != NULL)
	{
		if(CompararClientes(aux->Elemento,C)==0)
			return aux->Elemento;
		aux = aux->Prox;
	}
	return dummy;
}


PNodo ProcurarAnterior (CLIENTE X, PNodo L){
  PNodo  Ant = NULL; 
  while (L != NULL && CompararClientes(L->Elemento, X) != 0){
    Ant = L;
    L = L->Prox;
  } 
  return Ant;
}

PNodo RemoverC (CLIENTE X, PNodo L){ 
  PNodo P, PAnt;
  PAnt = ProcurarAnterior(X, L); 
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

int PesquisarRec (CLIENTE X, PNodo L){
  if (L == NULL) 
    return  0;
  if (CompararClientes(L->Elemento, X) == 0) 
    return  1; 
  else 
    return PesquisarRec(X, L->Prox);
}

PNodo RemoverComNIF(long long int NIF, PNodo L,int * removido)
{
    CLIENTE RX;
    RX.NIF = NIF;
    if(PesquisarRec(RX,L)==1)
	{
		(*removido) = 1;
		L = RemoverC(RX,L);
	}
        
    return L;
}

PNodo AlterarComNIF (PNodo L)
{
	long long int NIF;
	printf("Qual é o NIF?\n");
	scanf("%lld",&NIF);
	int n;
	char Nome[100];
	char Morada[100];
	long long int nTelefone = 0;
	//PNodo P = NULL; //se existir, pedir o que quer alterar;
	CLIENTE C,New;
  	if (ProcurarNIF(NIF, L,&C)==1) 
	  printf("Erro: esse 'NIF' não está associado a nenhum Cliente, por favor verifique se inseriu o 'NIF' corretamente.\n");
  	
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
				C.NIF = NIF;
				C = DevolveCliente(C,L);
				New = C;
				strcpy(New.Nome,Nome);
				L = AtualizarCliente(C,New,L);
				break;

			//Morada
			case 2:
				printf("Insira uma 'Morada' válida: ");
				scanf("\n%[^\n]s",Morada);
				C.NIF = NIF;
				C = DevolveCliente(C,L);
				New = C;
				strcpy(New.Morada,Morada);
				L = AtualizarCliente(C,New,L);
				break;

			case 3:
				printf("Insira um 'Número de telefone' válido: ");
				scanf("%lld", &nTelefone);
				C.NIF = NIF;
				C = DevolveCliente(C,L);
				New = C;
				New.Telefone = nTelefone;
				L = AtualizarCliente(C,New,L);
				break;
		}
		printf("\n");
		if(n>=1 && n <=3)
		printf("Mudança feita com sucesso.\n");
  	}

  	return L;
}

//Consultar por
PNodoFila ConsultarClientesPor(PNodo L,PNodoFila Fila)
{
	int n;
	long long int NIF = 0;
	char Nome[100];
	char Morada[100];
	long long int nTelefone = 0;
	printf("Escolha uma das seguintes opcões:\n");
	printf("1 - NIF\n");
	printf("2 - Nome\n");
	printf("3 - Morada\n");
	printf("4 - Número de telefone\n");
	printf("5 - Todos\n");

	printf("0 - Sair para o menu.\n");
	printf("Para sair insira um número que seja diferente dos números acima.\n");
	scanf("%d",&n);
	switch(n)
	{
		//NIF
		case 1:
			printf("Insira um 'NIF' válido: ");
			scanf("%lld", &NIF);
			printf("-----------------------------\n");
			Fila = ConsultarClientesPorNIF(NIF, L,Fila);
			break;

		//Nome
		case 2:
			printf("Insira um 'Nome' válido: ");
			scanf("\n%[^\n]s",Nome);
			printf("-----------------------------\n");
			Fila= ConsultarClientesPorNome(Nome,L,Fila);
			break;

		//Morada
		case 3:
			printf("Insira uma 'Morada' válida: ");
			scanf("\n%[^\n]s",Morada);
			printf("-----------------------------\n");
			Fila= ConsultarClientesPorMorada(Morada, L,Fila);
			break;

		case 4:
			printf("Insira um 'Número de telefone' válido: ");
			scanf("%lld", &nTelefone);
			printf("-----------------------------\n");
			Fila = ConsultarClientesPornTelefone(nTelefone,L,Fila);
			break;

		case 5:
			Fila= ConsultarClientesTodos(L,Fila);
			break;

		case 0:
			break;
	}
	return Fila;
}

void guardarClientes(PNodo L, FILE * FP)
{
	while(L!=NULL) 
	{
		fwrite(&L->Elemento,sizeof(CLIENTE),1,FP);
		L = L->Prox;
	}
}

PNodo novoClientes(PNodo L)
{
	while(L!=NULL)
	{
		L = RemoverC(L->Elemento,L);
	}
	return L;
}