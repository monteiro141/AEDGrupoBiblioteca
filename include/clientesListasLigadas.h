#include "livrosArvores.h"

#include <stdlib.h>



PNodo Criar ();
PNodo CriarNodo (CLIENTE X);
int Pesquisar (CLIENTE C, PNodo L);
PNodo ProcurarNIF (long long int NIF, PNodo L);
PNodo ProcurarAnteriorNIF (long long int NIF, PNodo L);
PNodo ProcurarNome (char* Nome, PNodo L);
PNodo ProcurarMorada (char* Morada, PNodo L);
PNodo ProcurarnTelefone (long long int nTele, PNodo L);

void ConsultarClientesPorNIF(long long int NIF, PNodo L,PNodoFila Fila);
void ConsultarClientesPorNome(char* Nome, PNodo L,PNodoFila Fila);
void ConsultarClientesPorMorada(char* Morada, PNodo L,PNodoFila Fila);
void ConsultarClientesPornTelefone(long long int nTele, PNodo L,PNodoFila Fila);

PNodo InserirInicio (CLIENTE C, PNodo L);
PNodo AtualizarCliente(CLIENTE C, CLIENTE X, PNodo L);
CLIENTE DevolveCliente(CLIENTE C, PNodo L);
PNodo RemoverComNIF (long long int NIF, PNodo L);
PNodo AlterarComNIF (PNodo L);

void ConsultarClientesPor(PNodo L,PNodoFila Fila);
/*----------Guardar Clientes----------*/
void guardarClientes(PNodo L, FILE * FP);