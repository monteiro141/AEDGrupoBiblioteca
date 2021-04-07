
struct NodoPilha {
  INFO  Elemento;
  struct NodoPilha *Ant;
};

typedef struct NodoPilha *PNodoPilha;

// Operações sobre o Nodo

PNodoPilha CriarNodoPilha (INFO X){
  PNodoPilha P;
  P = (PNodoPilha) malloc(sizeof(struct NodoPilha));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Ant = NULL;
  return P;
}

PNodoPilha LibertarNodoPilha (PNodoPilha P){ 
  free(P);
  P = NULL;
  return P;
}


// Operações sobre a Pilha

PNodoPilha CriarPilha (){
  PNodoPilha P;
  P = NULL;
  return P;
}

int PilhaVazia (PNodoPilha Pilha){
  if (Pilha == NULL)
    return 1;
  else
    return 0;
}

PNodoPilha Push (INFO X, PNodoPilha Pilha){
  PNodoPilha Novo;
  Novo = CriarNodoPilha(X);
  if (Novo == NULL)
    return  Pilha;
  Novo->Ant = Pilha;
  Pilha = Novo;
  return Pilha;
}

PNodoPilha Pop (PNodoPilha Pilha){
  PNodoPilha PAux;
  PAux = Pilha;
  Pilha = Pilha->Ant;
  PAux = LibertarNodoPilha(PAux);
  return Pilha;
}

INFO Topo (PNodoPilha Pilha){
  return Pilha->Elemento;
}


