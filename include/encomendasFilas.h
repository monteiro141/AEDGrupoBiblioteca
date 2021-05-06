#include "clientesListasLigadas.h"


PNodoFila CriarNodoFila (ENCOMENDA X);
int FilaVazia (PNodoFila Fila);
PNodoFila CriarFila ();


PNodoFila ConsultarEncomendas(PNodoFila Fila);

PNodoFila RemoverEncomenda(PNodoFila Fila,ENCOMENDA * e);

PNodoFila RemoverPeloNIF(long long int NIF, PNodoFila Fila);
PNodoFila RemoverPeloISBN(long long int ISBN, PNodoFila Fila);

PNodoFila guardarEncomendas(PNodoFila Fila, FILE * FP);

PNodoFila novoEncomendas(PNodoFila Fila);