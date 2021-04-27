#include <stdio.h>
#include <string.h>
#include "livrosArvores.h"
#include <stdlib.h>

/*----------Funções Auxiliares----------*/
PNodoAB CriarNodoAB(LIVRO L)
{
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

int verificarEquilibrio(PNodoAB t)
{
    int e, d;

    e = AlturaAB(t->Esquerda);
    d = AlturaAB(t->Direita);
    if(abs(e-d) > 1)
        return 0;

    if(t->Esquerda != NULL && verificarEquilibrio(t->Esquerda) == 0)
        return 0;
    if(t->Direita != NULL && verificarEquilibrio(t->Direita) == 0)
        return 0;
    return 1;
}

void ABPEqInsercaoBinaria (PNodoAB *TE, LIVRO L[], int inicio, int fim) {
  int  meio;
  if (inicio > fim)
    return ;
  if (inicio == fim){
    *TE = InserirABP(*TE, L[inicio]);
    return;
  }
  
  meio = (inicio + fim) / 2;
  *TE = InserirABP(*TE, L[meio]);
  ABPEqInsercaoBinaria(TE, L, inicio, meio-1);
  ABPEqInsercaoBinaria(TE, L, meio+1, fim);
  
}

void CriarSequenciaEmOrdem (PNodoAB T, LIVRO L[], int *N){
  if (T != NULL){
    CriarSequenciaEmOrdem(T->Esquerda, L, N);
    L[*N] = T->Elemento;
    *N = (*N) + 1;
    CriarSequenciaEmOrdem(T->Direita, L, N);
  }
}

PNodoAB CriarABPEquilibradaIB (PNodoAB t){
  LIVRO *Lista;
  PNodoAB TE;
  int  N = 0, Num;
  TE = CriarAB();
  Num = NumeroNodosAB(t);
  if (t == NULL)
    return NULL;
  Lista = (LIVRO *) malloc(Num * sizeof(LIVRO));
  if (Lista == NULL)
    return NULL;
  CriarSequenciaEmOrdem(t, Lista, &N);
  ABPEqInsercaoBinaria(&TE, Lista, 0, N-1);
  return TE;
}

/*------------------------------------------------------------*/
/*----------Inserir livro----------*/
PNodoAB InserirLivro(PNodoAB t, LIVRO L)
{
  if(PesquisarABP(t,L)==0) //Livro não existe
    t = InserirABP(t,L);
  else
    printf("Não pode inserir algo que ja existe!(ISBN)\n");

  if(verificarEquilibrio(t)==0)
    t = CriarABPEquilibradaIB(t);

  return t;
}

/*----------Remover livro----------*/
PNodoAB RemoverLivro(PNodoAB t, LIVRO L)
{
  if(PesquisarABP(t,L)==0)
  {
    printf("Livro não existe!\n");
    return t;
  }
  t = RemoverABP(t,L);

  if(verificarEquilibrio(t)==0)
    t = CriarABPEquilibradaIB(t);

    return t;
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

  t = AlterarLivroAux(t,L,X);

  if(verificarEquilibrio(t)==0)
    t = CriarABPEquilibradaIB(t);
    
  return t;
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
    ConsultarLivroISBN(t->Esquerda,ISBN);
    ConsultarLivroISBN(t->Direita,ISBN);  
}

void ConsultarLivroTitulo(PNodoAB t, char * Titulo)
{
  if(t==NULL)
    return;
  if(strstr(t->Elemento.Titulo,Titulo)!=NULL)
    MostrarLivro(t->Elemento);
  ConsultarLivroTitulo(t->Esquerda,Titulo);
  ConsultarLivroTitulo(t->Direita,Titulo);
}

void ConsultarLivroAutorAnoPublicacao(PNodoAB t, char * Autor, int AnoPub)
{
  if(t==NULL)
    return;
    if((strcmp(t->Elemento.PrimeiroAutor,Autor)==0 || strcmp(t->Elemento.SegundoAutor,Autor)==0) && t->Elemento.AnoPublicacao == AnoPub)
      MostrarLivro(t->Elemento);
  ConsultarLivroAutorAnoPublicacao(t->Esquerda,Autor,AnoPub);
  ConsultarLivroAutorAnoPublicacao(t->Direita,Autor,AnoPub);
}

void ConsultarLivroEditoraAreaC(PNodoAB t, char * Editora, char * AreaC)
{
  if(t==NULL)
    return;
  if(strstr(t->Elemento.Editora,Editora)!=NULL && strstr(t->Elemento.AreaCientifica,AreaC)!=NULL)
    MostrarLivro(t->Elemento);
  ConsultarLivroEditoraAreaC(t->Esquerda,Editora,AreaC);
  ConsultarLivroEditoraAreaC(t->Direita,Editora,AreaC);
}

void ConsultarLivro(int n, PNodoAB t)
{
  long long int ISBN = 0;
  char Titulo[100];
  char Autor[100];
  char Editora[100];
  char AreaC[100];
  int AnoPub=0;
    //fazer menus para mostrar o que cada numero significa
    switch(n)
    {
        //NIF
        case 1:
        printf("Qual o ISBN? ");
        scanf("%d",&ISBN);
        ConsultarLivroISBN(t,ISBN);
        break;

        //Nome
        case 2:
        printf("Qual o Titulo? ");
        scanf("\n%[^\n]s",Titulo);
        ConsultarLivroTitulo(t,Titulo);
        break;

        //Morada
        case 3:
        printf("Qual o Titulo? ");
        scanf("\n%[^\n]s",Autor);
        printf("Qual o Titulo? ");
        scanf("%d",AnoPub);
        ConsultarLivroAutorAnoPublicacao(t,Autor,AnoPub);
        break;

        case 4:
        printf("Qual o Editora? ");
        scanf("\n%[^\n]s",Editora);
        printf("Qual o AreaC? ");
        scanf("\n%[^\n]s",AreaC);
        ConsultarLivroEditoraAreaC(t,Editora,AreaC);
        break;
        default:
        printf("Operação inválida, por favor insira um número válido.\n");
    }
}