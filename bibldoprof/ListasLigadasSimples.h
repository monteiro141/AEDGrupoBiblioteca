#include <stdlib.h>
struct Nodo {
  INFO   Elemento;
  struct Nodo *Prox;
};

typedef struct Nodo *PNodo;


PNodo Criar (){
  PNodo L;
  L = NULL;
  return L;
}

PNodo CriarNodo (INFO X){
  PNodo P;
  P = (PNodo) malloc(sizeof(struct Nodo));
  if (P == NULL)
    return NULL;
  P->Elemento = X;
  P->Prox = NULL;
  return P;
}

void LibertarNodo (PNodo P){ 
  free(P);
  P = NULL;
}

int Vazia (PNodo L){
  if (L == NULL)
    return 1;
  else
    return 0;
}


void Listar (PNodo L){
  PNodo P = L;
  while (P != NULL){
    MostrarElemento(P->Elemento);
    P = P->Prox;
  }
  printf("\n\n");
}

void ListarRec (PNodo L){
  if (L != NULL){
    MostrarElemento(L->Elemento);
    ListarRec(L->Prox);
  }
}

void ListarContrarioRec (PNodo L){
  if (L != NULL){
    ListarContrarioRec(L->Prox);
    MostrarElemento(L->Elemento);
  }
}

PNodo InserirInicio (INFO X, PNodo L){
  PNodo P;
  P = CriarNodo(X);
  if (P == NULL)
    return L;
  P->Prox = L;
  L = P;
  return L;
}

// ###############  A2  ########################


int Pesquisar (INFO X, PNodo L){ 
  while (L != NULL && CompararElementos(L->Elemento, X) != 0)
    L = L->Prox; 
  if (L == NULL)
    return 0; 
  else
    return 1;
} 

int PesquisarRec (INFO X, PNodo L){
  if (L == NULL) 
    return  0;
  if (CompararElementos(L->Elemento, X) == 0) 
    return  1; 
  else 
    return PesquisarRec(X, L->Prox);
}

PNodo ProcurarAnterior (INFO X, PNodo L){
  PNodo  Ant = NULL; 
  while (L != NULL && CompararElementos(L->Elemento, X) != 0){
    Ant = L;
    L = L->Prox;
  } 
  return Ant;
}

PNodo ProcurarAnteriorRec (INFO X, PNodo L){ 
  if (CompararElementos(L->Elemento, X) == 0) 
    return  NULL;   //  só acontece se X estiver no início de L 
  if (CompararElementos(L->Prox->Elemento, X) == 0) 
    return  L; 
  return ProcurarAnteriorRec(X, L->Prox);
}

// remover X da lista L, em que X está na lista
PNodo Remover (INFO X, PNodo L){ 
  PNodo P, PAnt;
  PAnt = ProcurarAnterior(X, L); 
  if (PAnt == NULL){   // remover elemento do início de L
    P = L;
    L = L->Prox;
  } 
  else{
    P = PAnt->Prox;
    PAnt->Prox = P->Prox; // ou (PAnt->Prox)->Prox
  } 
  LibertarNodo(P); 
  return  L;
}

// remover X da lista L, em que X está na lista
PNodo RemoverRec (INFO X, PNodo L, PNodo LAux) {
  PNodo  P;
  if (CompararElementos(L->Elemento, X) == 0){   // X está no início da Lista L
    P = L;
    L = L->Prox;
    free(P);
    return  L;
  }
  if (CompararElementos(LAux->Prox->Elemento, X) == 0){    
    // X está na lista L, mas não no inicio
    P = LAux->Prox;
    LAux->Prox = P->Prox;    // ou LAux->Prox->Prox;
    free(P);
    return L;
  }
  return RemoverRec(X, L, LAux->Prox);
}

// ###############  A3  ########################

int Tamanho (PNodo L){
  int  tam = 0; 
  while (L != NULL){
    tam++;
    L = L->Prox;
  } 
  return tam;
}

int TamanhoRec (PNodo L){ 
  if (L == NULL) 
    return 0; 
  else 
    return 1 + TamanhoRec(L->Prox);
}

PNodo InserirFim (INFO X, PNodo L){ 
  PNodo P, PAux;
  P = CriarNodo(X); 
  if (P == NULL) 
    return L; 
  if (L == NULL) 
    return P;
  PAux = L; 
  while (PAux->Prox != NULL)    // marcar o elemento do fim de L
    PAux = PAux->Prox;
  PAux->Prox = P; 
  return  L; 
}

PNodo InserirFimRec (INFO X, PNodo L){
  PNodo P; 
  if (L == NULL){      // só acontece se a lista inicial for vazia
    P = CriarNodo(X); 
    if (P != NULL)
      L = P; 
    return  L;
  } 
  if (L->Prox == NULL){      // fim da lista L
    P = CriarNodo(X); 
    if (P != NULL)
      L->Prox = P;
  } 
  else 
    InserirFimRec(X, L->Prox);    // o que devolve não interessa 
  return L;    // devolve o início da lista 
}

// assume-se que a lista está ordenada por ordem crescente
PNodo ProcurarInserirOrdem (INFO X, PNodo L){ 
  PNodo Ant = NULL; 
  while (L != NULL && CompararElementos(L->Elemento, X) < 0){
    Ant = L;
    L = L->Prox;
  } 
  return Ant; 
} 

PNodo InserirOrdem (INFO X, PNodo L){
  PNodo P, PAnt;
  P = CriarNodo(X); 
  if (P == NULL) 
    return  L; 
  if (L == NULL) 
    return  P;    // a lista L inicia-se em P
  PAnt = ProcurarInserirOrdem(X, L); 
  if (PAnt == NULL){   // inserir no início de L
    P->Prox = L; 
    return  P;
  }   
  P->Prox = PAnt->Prox;
  PAnt->Prox = P;
  return  L; 
}








