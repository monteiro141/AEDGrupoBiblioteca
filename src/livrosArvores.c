#include <stdio.h>
#include <string.h>
#include "livrosArvores.h"
#include <stdlib.h>

/*----------Funções Auxiliares----------*/
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
    if(CompararLivros(L,t->Elemento)==0)
      return 1;
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

PNodoAB LibertarNodoAB(PNodoAB t){
  t->Esquerda = NULL;
  t->Direita = NULL;
  free(t);
  t = NULL;
  return t;
}

PNodoAB RemoverNodoABP (PNodoAB t){
  PNodoAB  R;
  LIVRO  L;
  if (t->Esquerda == NULL && t->Direita == NULL) {   
    t = LibertarNodoAB(t);
    return t;
  }
  if (t->Esquerda == NULL) {  
    R = t;
    t = t->Direita;
    R = LibertarNodoAB(R);
    return t;
  }
  if (t->Direita == NULL) {     
    R = t;
    t = t->Esquerda;
    R = LibertarNodoAB(R);
    return t;
  }
  t->Direita = SubstituirNodoDireita(t->Direita, &L);
  t->Elemento = L;
  return t;
}

PNodoAB RemoverABP (PNodoAB t, LIVRO L) {
  if (CompararElementos(L, t->Elemento) == 0) {
    t = RemoverNodoABP(t);
    return t;
  }    
  if (CompararElementos(L, t->Elemento) == -1)
    t->Esquerda = RemoverABP(t->Esquerda, L);
  else
    t->Direita = RemoverABP(t->Direita, L);
  return t;
}

/*------------------------------------------------------------*/
/*----------Inserir livro----------*/
PNodoAB InserirLivro(PNodoAB t, LIVRO L)
{
  return InserirABP(t,L);
}

/*----------Remover livro----------*/
PNodoAB RemoverLivro(PNodoAB t, LIVRO L)
{
    return RemoverABP(t,L);
}

/*----------Alterar livro(ISBN)----------*/
PNodoAB AlterarLivroAux(PNodoAB t, LIVRO L, LIVRO X)
{
    if(t==NULL)
        return t;
    if(CompararLivros(L,t->Elemento)==0)
    {
      t->Elemento = X;
      return t;
    }
    if(CompararLivros(L,t->Elemento)==-1)
        return AlterarLivroAux(t->Esquerda,L,X);
    else
        return AlterarLivroAux(t->Direita,L,X);  
}

PNodoAB AlterarLivro(PNodoAB t, LIVRO L,LIVRO X)
{
  if(PesquisarABP(t,L)==0)
  {
    printf("Livro não existe!\n");
    return t;
  }
  return AlterarLivroAux(t,L,X);
}

/*----------Consultar Livro----------*/
void ConsultarLivroISBN(PNodoAB t, int ISBN)
{
    if(t==NULL)
        return;
    if(t->Elemento.ISBN == ISBN)
    {
      MostrarLivro(t->Elemento);
      return;
    }
    ConsultarLivroISBN(t->Direita,ISBN);
    ConsultarLivroISBN(t->Esquerda,ISBN);  
}
/*void ConsultarLivroISBN(PNodoAB t, int ISBN)
{
    if(t==NULL)
        return;
    if(strstr(L,t->Elemento)==0)
    {
      t->Elemento = X;
      return t;
    }
    if(CompararLivros(L,t->Elemento)==-1)
        return PesquisarABP(t->Esquerda,L);
    else
        return PesquisarABP(t->Direita,L);      
}*/