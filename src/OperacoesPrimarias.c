#include <string.h>
#include <time.h>
#include <stdio.h>
#include "OperacoesPrimarias.h"
#include <stdlib.h>
/*---------------------------Livro + Funções---------------------------*/
void MostrarLivro (LIVRO X)
{
    printf("ISBN: %lld\n",X.ISBN);
    printf("Titulo: %s.\n",X.Titulo);
    printf("Primeiro Autor: %s.\n",X.PrimeiroAutor);
    printf("Segundo Autor: %s.\n",X.SegundoAutor);
    printf("Editora: %s.\n",X.Editora);
    printf("Ano Publicacao: %d.\n",X.AnoPublicacao);
    printf("Area Cientifica: %s.\n",X.AreaCientifica);
    printf("Preco: %.2f.\n",X.Preco);
    printf("Quantidade em stock: %d.\n",X.QuantidadeStock);
}
LIVRO CriarLivro ()
{
    LIVRO x;
    /*
    Testar
    x.ISBN = 123;
    strcpy(x.Titulo,"cenas");
    strcpy(x.PrimeiroAutor,"pautor");
    strcpy(x.SegundoAutor,"sautor");
    strcpy(x.Editora,"Edit");
    x.AnoPublicacao = 1000;
    strcpy(x.AreaCientifica,"AreaC");
    x.Preco = 100;
    x.QuantidadeStock = 999;
    */
    /*Reparar os \n do buffer*/
    printf("ISBN: ");
    scanf("%lld",&x.ISBN);

    printf("Titulo: ");
    scanf("\n%[^\n]s",x.Titulo);

    printf("Primeiro Autor: ");
    scanf("\n%[^\n]s",x.PrimeiroAutor);

    printf("Segundo Autor: ");
    scanf("\n%[^\n]s",x.SegundoAutor);

    printf("Editora: ");
    scanf("\n%[^\n]s",x.Editora);

    printf("Ano Publicacao: ");
    scanf("%d",&x.AnoPublicacao);

    printf("Area Cientifica: ");
    scanf("\n%[^\n]s",x.AreaCientifica);

    printf("Preco: ");
    scanf("%f",&x.Preco);

    printf("Quantidade em stock: ");
    scanf("%d",&x.QuantidadeStock);
    
    return x;
}
int CompararLivros (LIVRO x, LIVRO y)
{
    if(x.ISBN > y.ISBN)
        return 1;
    else if (x.ISBN < y.ISBN)
        return -1;
    else
        return 0;
}

/*---------------------------Encomenda + funções---------------------------*/

void MostrarEncomenda (ENCOMENDA E)
{
    printf("ISBN: %lld.\n",E.ISBN);
    printf("NIF: %lld.\n",E.NIF);
    printf("Encomenda: %d/%d/%d\n",E.Encomenda.Dia,E.Encomenda.Mes,E.Encomenda.ano);
    printf("Quantidade: %d\n",E.Quantidade);
    printf("Preço Total: %.2f\n",E.PrecoTotal);
}

int CriarEncomenda (CLIENTE C, LIVRO L,ENCOMENDA * E)
{
    int n=0;
    time_t now = time(NULL);
    struct tm *pt = localtime(&now);
    printf("\nQuantos quer encomendar? ");
    scanf("%d",&n);
    if(n <= L.QuantidadeStock)
    {
        (*E).ISBN = L.ISBN;
        (*E).NIF = C.NIF;
        (*E).Encomenda.Dia = pt->tm_mday;
        (*E).Encomenda.Mes = pt->tm_mon +1;
        (*E).Encomenda.ano = pt->tm_year +1900;
        (*E).Quantidade = n;
        (*E).PrecoTotal = (*E).Quantidade * L.Preco;
        return 0;
    }
    return 1;
}

int CompararEncomendas (ENCOMENDA X, ENCOMENDA Y)
{

    if(X.ISBN > Y.ISBN)
        return 1;
    else if (X.ISBN < Y.ISBN)
        return -1;
    else
        return 0;
}


/*---------------------------Cliente + funções---------------------------*/

void MostrarCliente (CLIENTE C)
{
    printf("NIF: %lld.\n",C.NIF);
    printf("Nome: %s.\n",C.Nome);
    printf("Morada: %s.\n",C.Morada);
    printf("Telefone: %lld.\n",C.Telefone);
    printf("*Listar encomendas*\n");
}
CLIENTE CriarCliente()
{
    CLIENTE C;
    printf("NIF: ");
    scanf("%lld",&C.NIF);
    printf("Nome: ");
    scanf("\n%[^\n]s",C.Nome);
    printf("Morada: ");
    scanf("\n%[^\n]s",C.Morada);
    printf("Telefone: ");
    scanf("%lld",&C.Telefone);
    C.numeroEncomendas = 0;
    C.ListaDeCompras = malloc(C.numeroEncomendas*sizeof(ENCOMENDA));
    return C;
}
int CompararClientes (CLIENTE X, CLIENTE Y);