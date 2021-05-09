#include "OperacoesPrimarias.h"


/*----------Funções Auxiliares----------*/
PNodoAB CriarNodoAB(LIVRO L);

int PesquisarABP (PNodoAB t, LIVRO L);

PNodoAB InserirABP (PNodoAB t, LIVRO L);

int AlturaAB (PNodoAB t);

PNodoAB LibertarNodoAB(PNodoAB t);
PNodoAB DestruirAB(PNodoAB T);

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
/*Esta função tem por base inserir um livro.
Primeiro verifica se o ISBN do livro a inserir existe, se não então adiciona, caso contrário 
printa um erro.
Ao fim de inserir(ou não) verifica o equilibra a arvore se for necessário e retorna a arvoreLivro*/
PNodoAB InserirLivro(PNodoAB t, LIVRO L);

/*----------Remover livro----------*/
/*Este função tem por base remover um dado livro
Primeiro pesquisa pelo livro dado ISBN, caso não consiga encontrar então printa um aviso e retorna a arvore
Caso contrário vai remover o dado livro pelo ISBN e equilibra a arvore se for necessário*/
PNodoAB RemoverLivro(PNodoAB t, LIVRO L,int * removido);

/*----------Alterar livro(ISBN)----------*/
/*Esta função tem por base alterar o livro, primeiro pesquisa pelo mesmo, caso não encontre retorna arvore
Caso contrário altera o livro atual com o novo livro passo como parametro e verifica equilibrio para depois retornar
a arvore*/
PNodoAB AlterarLivroAux(PNodoAB t, LIVRO L, LIVRO X);
PNodoAB AlterarLivro(PNodoAB t, LIVRO L,LIVRO X);

/*----------Consultar Livro----------*/
/*Esta função tem por base devolver um livro dado um livro pelo ISBN*/
LIVRO DevolveLivro(PNodoAB t, LIVRO L);
/*Esta função tem por base mostrar todos os livros (Raiz-Esq-Dir)*/
void ConsultarLivroTodos(PNodoAB t);
/*Esta função tem por base mostrar o livro com o dado ISBN*/
void ConsultarLivroISBN(PNodoAB t, long long int ISBN);
/*Esta função tem por base mostrar o livro com o dado titulo(ou parte dele), pode haver mais do que um*/
void ConsultarLivroTitulo(PNodoAB t, char * Titulo);
/*Esta função tem por base mostrar o livro com o dado Autor e ano publicacao, pode haver mais do que um*/
void ConsultarLivroAutorAnoPublicacao(PNodoAB t, char * Autor, int AnoPub);
/*Esta função tem por base mostrar o livro com a dada editora(ou parte dela) e Area cientifica, pode haver mais do que um*/
void ConsultarLivroEditoraAreaC(PNodoAB t, char * Editora, char * AreaC);
/*Esta função tem por base ser um caminho para as funções a cima de consultar*/
void ConsultarLivro(PNodoAB t);
/*----------Guardar Livro----------*/
/*Esta função tem por base guardar os livros (Raiz - Esq- Dir) no ficheiro*/
void guardarLivros(PNodoAB t, FILE * FP);
/*Esta função tem por base "limpar" a arvore para mais tarde ser usada*/
PNodoAB novoLivros(PNodoAB t);