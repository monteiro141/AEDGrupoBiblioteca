#include "OperacoesPrimarias.h"
struct NodoAB {
  LIVRO Elemento;
  struct NodoAB *Esquerda;
  struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;

/*----------Funções Auxiliares----------*/
PNodoAB CriarABP(LIVRO L);

PNodoAB CriarNodoAB(LIVRO L);

int PesquisarABP (PNodoAB t, LIVRO L);

PNodoAB InserirABP (PNodoAB t, LIVRO L);

int AlturaAB (PNodoAB t);

PNodoAB PesquisarAB (LIVRO L, PNodoAB t);

PNodoAB ProcurarFolhaAB (PNodoAB t, LIVRO *L);

PNodoAB LibertarNodoAB(PNodoAB t);

PNodoAB RemoverNodoABP (PNodoAB t);

PNodoAB RemoverABP (PNodoAB t, LIVRO L) ;

/*----------Inserir livro----------*/
PNodoAB InserirLivro(PNodoAB t, LIVRO L);

/*----------Remover livro----------*/
PNodoAB RemoverLivro(PNodoAB t, LIVRO L);

/*----------Alterar livro(ISBN)----------*/
PNodoAB AlterarLivroAux(PNodoAB t, LIVRO L, LIVRO X);
PNodoAB AlterarLivro(PNodoAB t, LIVRO L,LIVRO X);

/*----------Consultar Livro----------*/
void ConsultarLivroISBN(PNodoAB t, int ISBN);