#include <stdio.h>
#include "livrosArvores.h"
#include <stdlib.h>

PNodoAB CriarABP(LIVRO L)
{
    PNodoAB t = NULL;
    t = InserirABP(t,L);
    return t;
}

PNodoAB CriarNodoAB(LIVRO L){
  PNodoAB P = (PNodoAB) malloc(sizeof(struct NodoAB));
  if (P == NULL)
    return  NULL;
  P->Elemento = L;
  P->Esquerda = NULL;
  P->Direita = NULL;
  return P;
}

int PesquisarABP(PNodoAB t, LIVRO L)
{
    if(t==NULL)
        return 0;
    if(CompararLivros(L,t->Elemento)==-1)
        return PesquisarABP(t->Esquerda,L);
    else
        return PesquisarABP(t->Direita,L);
}


PNodoAB InserirABP (PNodoAB t, LIVRO L)
{
    if(t==NULL)
    {
        t=CriarNodoAB(L);
        return t;
    }
    if(CompararLivros(L,t->Elemento)==-1)
        t->Esquerda = InserirABP(t->Esquerda,L);
    else
        t->Direita = InserirABP(t->Direita,L);
    return t;     
}

PNodoAB LibertarNodoAB(PNodoAB t)
{   
    t->Esquerda = NULL;
    t->Direita = NULL;
    free(t);
    t = NULL;
    return t;
}

int AlturaAB (PNodoAB t)
{
    int  e, d;
    if (t == NULL)
      return -1;
    e = AlturaAB(t->Esquerda);
    d = AlturaAB(t->Direita);
    if (e > d)
      return (e + 1);  // e (altura da esquerda), 1 a raiz
    else
      return (d + 1);  // d (altura da direita), 1 a raiz
}

PNodoAB PesquisarAB (LIVRO L, PNodoAB t)
{
  PNodoAB P;
  if (t == NULL)
    return NULL;
  if (CompararLivros(L, t->Elemento) == 0)
    return t;
  P = PesquisarAB(L, t->Esquerda);
  if (P != NULL)
    return P;
  return PesquisarAB(L, t->Direita);    
}

PNodoAB ProcurarFolhaAB (PNodoAB t, LIVRO *L)
{
    if (t->Esquerda == NULL  &&  t->Direita == NULL) 
    {
        *L = t->Elemento;
        return t;
    }
    if (AlturaAB(t->Esquerda) > AlturaAB(t->Direita))
        return ProcurarFolhaAB(t->Esquerda, L);
    else
        return ProcurarFolhaAB(t->Direita, L);
}

PNodoAB RemoverNodoAB (PNodoAB t)
{
  PNodoAB P, R;
  LIVRO L;
  if (t->Esquerda == NULL && t->Direita == NULL) // T é uma folha
  {   
    t = LibertarNodoAB(t);
    return t;
  }
  if (t->Esquerda == NULL) 
  {   
    R = t;
    t = t->Direita;
    R = LibertarNodoAB(R);
    return t;
  }
  if (t->Direita == NULL) 
  {     
    R = t;
    t = t->Esquerda;
    R = LibertarNodoAB(R);
    return t;
  }
  P = ProcurarFolhaAB(t, &L);
  P = LibertarNodoAB(P);
  t->Elemento = L;
  return t;    
}

PNodoAB RemoverAB (PNodoAB t, LIVRO L)
{
  PNodoAB P;
  if (t == NULL)
    return NULL;
  if (CompararLivros(t->Elemento, L) == 0) {
    t = RemoverNodoAB(t);
    return t;
  }
  P = PesquisarAB(L, t->Esquerda);
  if (P != NULL)
    t->Esquerda = RemoverAB(t->Esquerda, L);
  else
    t->Direita = RemoverAB(t->Direita, L);
  return t;    
}