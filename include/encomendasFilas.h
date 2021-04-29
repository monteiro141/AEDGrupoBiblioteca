#include "clientesListasLigadas.h"


PNodoFila CriarNodoFila (ENCOMENDA X);
int FilaVazia (PNodoFila Fila);
PNodoFila CriarFila ();


PNodoFila ConsultarEncomendas(PNodoFila Fila);

PNodoFila RemoverEncomenda(PNodoFila Fila);

PNodoFila guardarEncomendas(PNodoFila Fila, FILE * FP);