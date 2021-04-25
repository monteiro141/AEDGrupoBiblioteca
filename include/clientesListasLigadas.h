#include "livrosArvores.h"

#include <stdlib.h>
struct Nodo {
  CLIENTE Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;

PNodo Criar ();
