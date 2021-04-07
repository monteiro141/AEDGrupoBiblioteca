#include <OperacoesPrimarias.h>
#include <stdio.h>
/*---------------------------Livro + Funções---------------------------*/
void MostrarLivro (LIVRO X)
{
    printf("ISBN: %d.\n",X.ISBN);
    printf("Titulo: %s.\n",X.Titulo);
    printf("PrimeiroAutor: %s.\n",X.PrimeiroAutor);
    printf("SegundoAutor: %s.\n",X.SegundoAutor);
    printf("Editora: %s.\n",X.Editora);
    printf("Ano Publicacao: %d.\n",X.AnoPublicacao);
    printf("Area Cientifica: %s.\n",X.AreaCientifica);
    printf("Preco: %.2f.\n",X.Preco);
    printf("Quantidade: %d.\n",X.Quantidade);
}
LIVRO CriarLivro ()
{
    /*ACABAR ISTO*/
    LIVRO X;

    return X;
}
int CompararLivros (LIVRO X, LIVRO Y);

/*---------------------------Encomenda + funções---------------------------*/

void MostrarEncomenda (ENCOMENDA X);
ENCOMENDA CriarEncomenda ();
int CompararEncomendas (ENCOMENDA X, ENCOMENDA Y);


/*---------------------------Cliente + funções---------------------------*/

void MostrarCliente (CLIENTE X);
CLIENTE CriarCliente  ();
int CompararClientes (CLIENTE X, CLIENTE Y);