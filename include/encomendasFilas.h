#include "clientesListasLigadas.h"


PNodoFila CriarNodoFila (ENCOMENDA X);
int FilaVazia (PNodoFila Fila);
PNodoFila CriarFila ();
PNodoFila Remover (PNodoFila Fila);

PNodoFila Inserir (ENCOMENDA X, PNodoFila Fila);

PNodoFila RemoverEncomendaDadoNIF(PNodoFila Fila);

PNodoFila ConsultarEncomendas(PNodoFila Fila);

PNodoFila guardarEncomendas(PNodoFila Fila, FILE * FP);