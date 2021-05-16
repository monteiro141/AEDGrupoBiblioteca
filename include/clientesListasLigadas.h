#ifndef CLIENTESLISTASLIGADAS_H
#define CLIENTESLISTASLIGADAS_H
#include "OperacoesPrimarias.h"
#include <stdio.h>
#include <stdlib.h>


PNodo Criar ();
PNodo CriarNodo (CLIENTE X);
int Pesquisar (CLIENTE C, PNodo L);
int ProcurarNIF (long long int NIF, PNodo L,CLIENTE * C);
PNodo ProcurarAnteriorNIF (long long int NIF, PNodo L);
int ProcurarNome (char* Nome, PNodo L,PNodoFila Fila);
int ProcurarMorada (char* Morada, PNodo L,PNodoFila Fila);
int ProcurarnTelefone (long long int nTele, PNodo L, PNodoFila Fila);

PNodoFila ConsultarClientesPorNIF(long long int NIF, PNodo L,PNodoFila Fila);
PNodoFila ConsultarClientesPorNome(char* Nome, PNodo L,PNodoFila Fila);
PNodoFila ConsultarClientesPorMorada(char* Morada, PNodo L,PNodoFila Fila);
PNodoFila ConsultarClientesPornTelefone(long long int nTele, PNodo L,PNodoFila Fila);
PNodoFila ConsultarClientesTodos(PNodo L, PNodoFila Fila);

PNodo InserirInicio (CLIENTE C, PNodo L);
PNodo AtualizarCliente(CLIENTE C, CLIENTE X, PNodo L);
CLIENTE DevolveCliente(CLIENTE C, PNodo L);
PNodo ProcurarAnterior (CLIENTE X, PNodo L);
PNodo RemoverC (CLIENTE X, PNodo L);
int PesquisarRec (CLIENTE X, PNodo L);
PNodo RemoverComNIF(long long int NIF, PNodo L,int * removido);
PNodo AlterarComNIF (PNodo L);

PNodoFila ConsultarClientesPor(PNodo L,PNodoFila Fila);
/*----------Guardar/Novo Clientes----------*/
void guardarClientes(PNodo L, FILE * FP);
PNodo novoClientes(PNodo L);

#endif
