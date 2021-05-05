#include "clientesListasLigadas.h"


PNodoFila CriarNodoFila (ENCOMENDA X);
int FilaVazia (PNodoFila Fila);
PNodoFila CriarFila ();


PNodoFila ConsultarEncomendas(PNodoFila Fila);

PNodoFila RemoverEncomenda(PNodoFila Fila,ENCOMENDA * e);

PNodoFila guardarEncomendas(PNodoFila Fila, FILE * FP);

PNodoFila novoEncomendas(PNodoFila Fila);