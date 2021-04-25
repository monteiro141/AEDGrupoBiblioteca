#include "OperacoesPrimarias.h"
struct NodoAB {
  LIVRO Elemento;
  struct NodoAB *Esquerda;
  struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;

PNodoAB CriarABP(LIVRO L);

PNodoAB CriarNodoAB(LIVRO L);

int PesquisarABP (PNodoAB t, LIVRO L);

PNodoAB InserirABP (PNodoAB t, LIVRO L);

PNodoAB LibertarNodoAB(PNodoAB P);

int AlturaAB (PNodoAB t);

PNodoAB PesquisarAB (LIVRO L, PNodoAB t);

PNodoAB ProcurarFolhaAB (PNodoAB t, LIVRO *L);

PNodoAB RemoverNodoAB (PNodoAB t);

PNodoAB RemoverAB (PNodoAB t, LIVRO L);
