#include "OperacoesPrimarias.h"
struct NodoAB {
  LIVRO Elemento;
  struct NodoAB *Esquerda;
  struct NodoAB *Direita;
};

typedef struct NodoAB *PNodoAB;

/*----------Funções Auxiliares----------*/
PNodoAB CriarNodoAB(LIVRO L);

int PesquisarABP (PNodoAB t, LIVRO L);

PNodoAB InserirABP (PNodoAB t, LIVRO L);

int AlturaAB (PNodoAB t);

PNodoAB LibertarNodoAB(PNodoAB t);

PNodoAB RemoverNodoABP (PNodoAB t);

PNodoAB RemoverABP (PNodoAB t, LIVRO L) ;

int verificarEquilibrio(PNodoAB t);

void ABPEqInsercaoBinaria (PNodoAB *TE, LIVRO L[], int inicio, int fim);

void CriarSequenciaEmOrdem (PNodoAB T, LIVRO L[], int *N);

PNodoAB CriarABPEquilibradaIB (PNodoAB t);

/*----------Inserir livro----------*/
PNodoAB InserirLivro(PNodoAB t, LIVRO L);

/*----------Remover livro----------*/
PNodoAB RemoverLivro(PNodoAB t, LIVRO L);

/*----------Alterar livro(ISBN)----------*/
PNodoAB AlterarLivroAux(PNodoAB t, LIVRO L, LIVRO X);
PNodoAB AlterarLivro(PNodoAB t, LIVRO L,LIVRO X);

/*----------Consultar Livro----------*/
void ConsultarLivroISBN(PNodoAB t, int ISBN);
void ConsultarLivroTitulo(PNodoAB t, char * Titulo);
void ConsultarLivroAutorAnoPublicacao(PNodoAB t, char * Autor, int AnoPub);
void ConsultarLivroEditoraAreaC(PNodoAB t, char * Editora, char * AreaC);
void ConsultarLivro(int n, PNodoAB t);
/*----------Guardar Livro----------*/
void guardarLivros(PNodoAB t, FILE * FP);