#include "livrosArvores.h"

#include <stdlib.h>

struct Nodo {
  CLIENTE Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;

PNodo Criar ();

int Pesquisar (CLIENTE C, PNodo L);

PNodo ProcurarNIF (long long int NIF, PNodo L);
PNodo ProcurarAnteriorNIF (long long int NIF, PNodo L);
PNodo ProcurarNome (char* Nome, PNodo L);
PNodo ProcurarMorada (char* Morada, PNodo L);
PNodo ProcurarnTelefone (long long int nTele, PNodo L);

void ConsultarClientesPorNIF(long long int NIF, PNodo L);
void ConsultarClientesPorNome(char* Nome, PNodo L);
void ConsultarClientesPorMorada(char* Morada, PNodo L);
void ConsultarClientesPornTelefone(long long int nTele, PNodo L);

PNodo InserirInicio (CLIENTE C, PNodo L);
PNodo RemoverComNIF (long long int NIF, PNodo L);
PNodo AlterarComNIF (PNodo L);

void ConsultarClientesPor(PNodo L);
/*----------Guardar Clientes----------*/
void guarderClientes(PNodo L, FILE * FP);