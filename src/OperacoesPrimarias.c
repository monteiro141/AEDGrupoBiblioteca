#include "../include/OperacoesPrimarias.h"
#include <string.h>
#include <stdio.h>
/*---------------------------Livro + Funções---------------------------*/
void MostrarLivro (LIVRO X)
{
    printf("ISBN: %f.\n",X.ISBN);
    printf("Titulo: %s.\n",X.Titulo);
    printf("Primeiro Autor: %s.\n",X.PrimeiroAutor);
    printf("Segundo Autor: %s.\n",X.SegundoAutor);
    printf("Editora: %s.\n",X.Editora);
    printf("Ano Publicacao: %d.\n",X.AnoPublicacao);
    printf("Area Cientifica: %s.\n",X.AreaCientifica);
    printf("Preco: %.2f.\n",X.Preco);
    printf("Quantidade: %d.\n",X.Quantidade);
}
LIVRO CriarLivro ()
{
    LIVRO x;
    char buffer[100]; //Buffer das strings
    /*
    Testar
    x.ISBN = 123;
    strcpy(x.Titulo,"cenas");
    strcpy(x.PrimeiroAutor,"pautor");
    strcpy(x.SegundoAutor,"sautor");
    strcpy(x.Editora,"Edit");
    x.AnoPublicacao = 1000;
    strcpy(x.AreaCientifica,"AreaC");
    x.Preco = 213;
    x.Quantidade = 321;
    */

    printf("\nISBN: ");
    scanf("%f",&x.ISBN);

    printf("\nTitulo: ");
    fgets(buffer,100,stdin);
    strcpy(x.Titulo,buffer);

    printf("\nPrimeiro Autor: ");
    fgets(buffer,100,stdin);
    strcpy(x.PrimeiroAutor,buffer);

    printf("\nSegundo Autor: ");
    fgets(buffer,100,stdin);
    strcpy(x.SegundoAutor,buffer);

    printf("\nEditora ");
    fgets(buffer,100,stdin);
    strcpy(x.Editora,buffer);

    printf("\nAno Publicacao: ");
    fgets(buffer,100,stdin);
    strcpy(x.Editora,buffer);

    printf("\nArea Cientifica: ");
    fgets(buffer,100,stdin);
    strcpy(x.AreaCientifica,buffer);

    printf("\nPreco: ");
    scanf("%f",&x.Preco);

    printf("\nQuantidade: ");
    scanf("%d",&x.Quantidade);
    return x;
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