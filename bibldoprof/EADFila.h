
struct NodoFila {
  INFO  Elemento;
  struct NodoFila *Prox;
};

typedef struct NodoFila *PNodoFila;

// Opera��es sobre o Nodo

PNodoFila CriarNodoFila (INFO X){
  PNodoFila P;
  P = (PNodoFila) malloc(sizeof(struct NodoFila));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

PNodoFila LibertarNodoFila (PNodoFila P){ 
  free(P);
  P = NULL;
  return P;
}


// Opera��es sobre a Pilha

PNodoFila CriarFila (){
  PNodoFila P;
  P = NULL;
  return P;
}

int FilaVazia (PNodoFila Fila){
  if (Fila == NULL)
    return 1;
  else
    return 0;
}

PNodoFila Juntar (INFO X, PNodoFila Fila){
  PNodoFila Novo, PAnt;
  Novo = CriarNodoFila(X);
  if (Novo == NULL)
    return Fila;
  if (FilaVazia(Fila)){
    Fila = Novo;
    return Fila;
  }
  PAnt = Fila;
  while(PAnt->Prox != NULL)
    PAnt = PAnt->Prox;
  PAnt->Prox = Novo;
  return Fila;
}


PNodoFila Remover (PNodoFila Fila){
  PNodoFila P;
  P = Fila;
  Fila = Fila->Prox;
  P = LibertarNodoFila(P);
  return Fila;
}


INFO Frente (PNodoFila Fila){
  return Fila->Elemento;
}



