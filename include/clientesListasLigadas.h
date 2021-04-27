#include "livrosArvores.h"

#include <stdlib.h>

struct Nodo {
  CLIENTE Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;

PNodo Criar ();
int Pesquisar (CLIENTE C, PNodo L);
PNodo ProcurarAnteriorNIF (long long int NIF, PNodo L);
PNodo InserirInicio (CLIENTE C, PNodo L);

PNodo RemoverComNIF (long long int NIF, PNodo L);
PNodo AlterarComNIF (long long int NIF, PNodo L);

void ConsultarClientesPor(int n, PNodo L);
void ConsultarPorNIF(long long int NIF, PNodo L);
void ConsultarPorNome(char* Nome, PNodo L);
void ConsultarPorMorada(char* Morada, PNodo L);