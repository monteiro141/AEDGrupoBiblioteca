#include "livrosArvores.h"

#include <stdlib.h>



PNodo Criar ();
PNodo CriarNodo (CLIENTE X);
int Pesquisar (CLIENTE C, PNodo L);
int ProcurarNIF (long long int NIF, PNodo L,CLIENTE * C);
PNodo ProcurarAnteriorNIF (long long int NIF, PNodo L);
PNodo ProcurarNome (char* Nome, PNodo L);
PNodo ProcurarMorada (char* Morada, PNodo L);
PNodo ProcurarnTelefone (long long int nTele, PNodo L);

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
PNodo RemoverComNIF(long long int NIF, PNodo L);
PNodo AlterarComNIF (PNodo L);

PNodoFila ConsultarClientesPor(PNodo L,PNodoFila Fila);
/*----------Guardar Clientes----------*/
void guardarClientes(PNodo L, FILE * FP);
