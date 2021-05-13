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

PNodoAB DestruirAB(PNodoAB T){
  if (T == NULL) 
    return NULL;
  T->Esquerda = DestruirAB(T->Esquerda);
  T->Direita = DestruirAB(T->Direita);
  return LibertarNodoAB(T);
}

PNodoAB SubstituirNodoDireita (PNodoAB T, LIVRO *X){
  PNodoAB  PAux;
  if (T->Esquerda == NULL) {
    *X = T->Elemento;
    PAux = T;
    T = T->Direita;
    PAux = LibertarNodoAB(PAux);
    return T;
  }
  T->Esquerda = SubstituirNodoDireita(T->Esquerda, X);
  return T;
}

PNodoAB SubstituirNodoEsquerda (PNodoAB T, LIVRO *X){
  PNodoAB  PAux;
  if (T->Direita == NULL) {
    *X = T->Elemento;
    PAux = T;
    T = T->Esquerda;
    PAux = LibertarNodoAB(PAux);
    return  T;
  }
  T->Direita = SubstituirNodoEsquerda(T->Direita, X);
  return T;
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
  //t->Esquerda = SubstituirNodoEsquerda(t->Esquerda, &L);
  t->Elemento = L;
  return t;
}

PNodoAB RemoverABP (PNodoAB t, LIVRO L) {
  if (CompararLivros(L, t->Elemento) == 0) {
    t = RemoverNodoABP(t);
    return t;
  }    
  if (CompararLivros(L, t->Elemento) == -1)
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

int NumeroNodosAB (PNodoAB T) {
  int  e, d;
  if (T == NULL)
    return 0;
  e = NumeroNodosAB(T->Esquerda);
  d = NumeroNodosAB(T->Direita);
  return (e + d + 1);
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
  TE = NULL;
  Num = NumeroNodosAB(t);
  if (t == NULL)
    return NULL;
  Lista = (LIVRO *) malloc(Num * sizeof(LIVRO));
  if (Lista == NULL)
  {
    free(Lista);
    return NULL;
  }
  CriarSequenciaEmOrdem(t, Lista, &N);
  ABPEqInsercaoBinaria(&TE, Lista, 0, N-1);
  free(Lista);
  t = DestruirAB(t);
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
  {
    printf("Equilibrou\n");
    t = CriarABPEquilibradaIB(t);
  }
  return t;
}

/*----------Remover livro----------*/
PNodoAB RemoverLivro(PNodoAB t, LIVRO L,int * removido)
{
  if(PesquisarABP(t,L)==0)
  {
    printf("Livro não existe!\n");
    return t;
  }
  t = RemoverABP(t,L);
  (*removido) = 1;
  if(verificarEquilibrio(t)==0)
    return CriarABPEquilibradaIB(t);
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
  PNodoAB aux = t;
  if(PesquisarABP(aux,L)==0)
  {
    printf("Livro não existe!\n");
    return t;
  }

  aux = AlterarLivroAux(aux,L,X);

  if(verificarEquilibrio(t)==0)
    t = CriarABPEquilibradaIB(t);
    
  return t;
}


/*----------Consultar Livro----------*/

LIVRO DevolveLivro(PNodoAB t, LIVRO L)
{
  LIVRO A;
  A.ISBN=-1;
    if(t==NULL)
        return A;
    if(CompararLivros(L,t->Elemento)==0)
      return t->Elemento;
    if(CompararLivros(L,t->Elemento)==-1)
        return DevolveLivro(t->Esquerda,L);
    else
        return DevolveLivro(t->Direita,L);
}

void ConsultarLivroTodos(PNodoAB t)
{
  if(t==NULL)
    return;
  MostrarLivro(t->Elemento);
  ConsultarLivroTodos(t->Esquerda);
  ConsultarLivroTodos(t->Direita);
}
void ConsultarLivroISBN(PNodoAB t, long long int ISBN)
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

void ConsultarLivro(PNodoAB t)
{
  int n;
  long long int ISBN = 0;
  char Titulo[100];
  char Autor[100];
  char Editora[100];
  char AreaC[100];
  int AnoPub=0;
    printf("1 - Consultar por ISBN.\n");
    printf("2 - Consultar por Titulo.\n");
    printf("3 - Consultar por Autor e Ano de publicação.\n");
    printf("4 - Consultar por Editora e Area Cientifica.\n");
    printf("5 - Consultar todos.\n");
    printf("Para sair insira um número que seja diferente dos números acima.\n");
	  scanf("%d",&n);
    //fazer menus para mostrar o que cada numero significa
    switch(n)
    {
        //NIF
        case 1:
        printf("Qual o ISBN? ");
        scanf("%lld",&ISBN);
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
        printf("Qual o Autor? ");
        scanf("\n%[^\n]s",Autor);
        printf("Qual o Ano de publibcação? ");
        scanf("%d",&AnoPub);
        ConsultarLivroAutorAnoPublicacao(t,Autor,AnoPub);
        break;

        case 4:
        printf("Qual o Editora? ");
        scanf("\n%[^\n]s",Editora);
        printf("Qual o AreaC? ");
        scanf("\n%[^\n]s",AreaC);
        ConsultarLivroEditoraAreaC(t,Editora,AreaC);
        break;

        case 5:
        ConsultarLivroTodos(t);
        break;
        default:
        printf("Operação inválida, por favor insira um número válido.\n");
    }
}

/*----------Guardar Livro----------*/
void guardarLivros(PNodoAB t, FILE * FP)
{
  if(t==NULL)
    return;
  fwrite(&t->Elemento,sizeof(LIVRO),1,FP);
  guardarLivros(t->Esquerda,FP);
  guardarLivros(t->Direita,FP);
}

PNodoAB novoLivros(PNodoAB t)
{
  while(t!=NULL)
  {
    t = DestruirAB(t);
  }
  return t;
}