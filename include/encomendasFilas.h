#include "clientesListasLigadas.h"

struct NodoFila {
  ENCOMENDA Elemento;
  struct NodoFila *Prox;
};

typedef struct NodoFila *PNodoFila;

PNodoFila CriarFila ();