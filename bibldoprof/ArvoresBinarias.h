
struct NodoAB {
  INFO  Elemento;
  struct NodoAB *Esquerda;
  struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;

// Opera��es sobre o Nodo

PNodoAB CriarAB(){ 
  PNodoAB T;
  T = NULL;
  return T;
}

int ABVazia(PNodoAB T){
  if (T == NULL)
    return 1;
  return 0;
}

PNodoAB CriarNodoAB(INFO X){
  PNodoAB P = (PNodoAB) malloc(sizeof(struct NodoAB));
  if (P == NULL)
    return  NULL;
  P->Elemento = X;
  P->Esquerda = NULL;
  P->Direita = NULL;
  return P;
}

PNodoAB LibertarNodoAB(PNodoAB P){
  P->Esquerda = NULL;
  P->Direita = NULL;
  free(P);
  P = NULL;
  return P;
}

PNodoAB DestruirAB(PNodoAB T){
  if (T == NULL) 
    return NULL;
  T->Esquerda = DestruirAB(T->Esquerda);
  T->Direita = DestruirAB(T->Direita);
  return LibertarNodoAB(T);
}

PNodoAB CopiarAB (PNodoAB T) {
  PNodoAB E, D, R;    // R � a nova �rvore, que � uma c�pia de T
  R = CriarAB();
  if (T == NULL)
    return R;
  E = CopiarAB(T->Esquerda);
  D = CopiarAB(T->Direita);
  R = CriarNodoAB(T->Elemento);
  R->Esquerda = E;
  R->Direita = D;
  return R;
}

int ABIguais (PNodoAB T, PNodoAB R) {
  if (T == NULL && R == NULL)  // se s�o ambas nulas, ent�o s�o iguais
    return 1;
  if (T == NULL || R == NULL)  // se uma delas � nula, ent�o s�o diferentes
    return 0;
  if (CompararElementos(T->Elemento, R->Elemento) != 0)  // ra�zes diferentes, �rvores diferentes
    return 0;
  if (ABIguais(T->Esquerda, R->Esquerda) == 0) // sub�rvores esq. diferentes
    return 0;
  if (ABIguais(T->Direita, R->Direita) == 0)  // sub�rvores direitas diferentes
    return 0;
  return 1;    // caso contr�rio, s�o iguais
}

int NumeroNodosAB (PNodoAB T) {
  int  e, d;
  if (T == NULL)
    return 0;
  e = NumeroNodosAB(T->Esquerda);
  d = NumeroNodosAB(T->Direita);
  return (e + d + 1);
}

int AlturaAB (PNodoAB T) {
  int  e, d;
  if (T == NULL)
    return -1;
  e = AlturaAB(T->Esquerda);
  d = AlturaAB(T->Direita);
  if (e > d)
    return (e + 1);  // e (altura da esquerda), 1 a raiz
  else
    return (d + 1);  // d (altura da direita), 1 a raiz
}

void ListarPreOrdemAB (PNodoAB T) {
  if (T != NULL) {
    MostrarElemento(T->Elemento);
    ListarPreOrdemAB(T->Esquerda);
    ListarPreOrdemAB(T->Direita);
  }
}

void ListarEmOrdemAB (PNodoAB T) {
  if (T != NULL) {
    ListarEmOrdemAB(T->Esquerda);
    MostrarElemento(T->Elemento);
    ListarEmOrdemAB(T->Direita);
  }
}

void ListarPosOrdemAB (PNodoAB T) {
  if (T != NULL) {
    ListarPosOrdemAB(T->Esquerda);
    ListarPosOrdemAB(T->Direita);
    MostrarElemento(T->Elemento);
  }
}

PNodoAB PesquisarAB (INFO X, PNodoAB T) {
  PNodoAB P;
  if (T == NULL)
    return NULL;
  if (CompararElementos(X, T->Elemento) == 0)
    return T;
  P = PesquisarAB(X, T->Esquerda);
  if (P != NULL)
    return P;
  return PesquisarAB(X, T->Direita);
}

PNodoAB InserirPorAlturaAB (PNodoAB T, INFO X) {
  if (T == NULL) {
    T = CriarNodoAB(X);
    return T;
  }
  if (AlturaAB(T->Esquerda) > AlturaAB(T->Direita))
    T->Direita = InserirPorAlturaAB(T->Direita, X);
  else
    T->Esquerda = InserirPorAlturaAB(T->Esquerda, X);
  return T;
}
    
PNodoAB ProcurarFolhaAB (PNodoAB T, INFO *X) {
  if (T->Esquerda == NULL  &&  T->Direita == NULL) {
    *X = T->Elemento;
    return T;
  }
  if (AlturaAB(T->Esquerda) > AlturaAB(T->Direita))
    return ProcurarFolhaAB(T->Esquerda, X);
  else
    return ProcurarFolhaAB(T->Direita, X);
}

PNodoAB RemoverNodoAB (PNodoAB T) {
  PNodoAB P, R;
  INFO  X;
  if (T->Esquerda == NULL && T->Direita == NULL) {   // T � uma folha
    T = LibertarNodoAB(T);
    return T;
  }
  if (T->Esquerda == NULL) {   //  s� um filho direito 
    R = T;
    T = T->Direita;
    R = LibertarNodoAB(R);
    return T;
  }
  if (T->Direita == NULL) {     // s� um filho esquerdo
    R = T;
    T = T->Esquerda;
    R = LibertarNodoAB(R);
    return T;
  }
  // 2 filhos: remover a folha escolhida e copiar a sua informa��o
  P = ProcurarFolhaAB(T, &X);
  P = LibertarNodoAB(P);
  T->Elemento = X;
  return T;
}


PNodoAB RemoverAB (PNodoAB T, INFO X) {
  PNodoAB P;
  if (T == NULL)
    return NULL;
  if (CompararElementos(T->Elemento, X) == 0) {
    T = RemoverNodoAB(T);
    return T;
  }
  P = PesquisarAB(X, T->Esquerda);
  if (P != NULL)
    T->Esquerda = RemoverAB(T->Esquerda, X);
  else
    T->Direita = RemoverAB(T->Direita, X);
  return T;
}

