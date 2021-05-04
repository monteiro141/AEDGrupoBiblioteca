#include "OperacoesPrimarias.h"


/*----------Funções Auxiliares----------*/
PNodoAB CriarNodoAB(LIVRO L);

int PesquisarABP (PNodoAB t, LIVRO L);

PNodoAB InserirABP (PNodoAB t, LIVRO L);

int AlturaAB (PNodoAB t);

PNodoAB LibertarNodoAB(PNodoAB t);

PNodoAB SubstituirNodoDireita (PNodoAB T, LIVRO *X);

PNodoAB SubstituirNodoEsquerda (PNodoAB T, LIVRO *X);

PNodoAB RemoverNodoABP (PNodoAB t);

PNodoAB RemoverABP (PNodoAB t, LIVRO L) ;

int verificarEquilibrio(PNodoAB t);

int NumeroNodosAB (PNodoAB T);

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
LIVRO DevolveLivro(PNodoAB t, LIVRO L);
void ConsultarLivroTodos(PNodoAB t);
void ConsultarLivroISBN(PNodoAB t, long long int ISBN);
void ConsultarLivroTitulo(PNodoAB t, char * Titulo);
void ConsultarLivroAutorAnoPublicacao(PNodoAB t, char * Autor, int AnoPub);
void ConsultarLivroEditoraAreaC(PNodoAB t, char * Editora, char * AreaC);
void ConsultarLivro(PNodoAB t);
/*----------Guardar Livro----------*/
void guardarLivros(PNodoAB t, FILE * FP);