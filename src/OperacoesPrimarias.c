#include "../include/OperacoesPrimarias.h"
#include <string.h>
#include <time.h>
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
    printf("Quantidade em stock: %d.\n",X.Quantidade);
}
LIVRO CriarLivro ()
{
    LIVRO x;
    char buffer[100]; //Buffer das strings
    /*
    Testar*/
    x.ISBN = 123;
    strcpy(x.Titulo,"cenas");
    strcpy(x.PrimeiroAutor,"pautor");
    strcpy(x.SegundoAutor,"sautor");
    strcpy(x.Editora,"Edit");
    x.AnoPublicacao = 1000;
    strcpy(x.AreaCientifica,"AreaC");
    x.Preco = 100;
    x.Quantidade = 999;
    
    /*Reparar os \n do buffer
    printf("\nISBN: ");
    scanf("%lf",&x.ISBN);
    getc(stdin); //clear buffer

    printf("\nTitulo: ");
    fgets(buffer,100,stdin);
    strcpy(x.Titulo,buffer);

    printf("\nPrimeiro Autor: ");
    fgets(buffer,100,stdin);
    strcpy(x.PrimeiroAutor,buffer);

    printf("\nSegundo Autor: ");
    fgets(buffer,100,stdin);
    strcpy(x.SegundoAutor,buffer);

    printf("\nEditora: ");
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

    printf("\nQuantidade em stock: ");
    scanf("%d",&x.Quantidade);
    */
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

void MostrarEncomenda (ENCOMENDA X)
{
    printf("ISBN: %d.\n",X.ISBN);
    printf("NIF: %d.\n",X.NIF);
    printf("Encomenda: %d/%d/%d\n",X.Encomenda.Dia,X.Encomenda.Mes,X.Encomenda.ano);
    
    if(X.Compra.Dia != -1)
        printf("Compra: %d/%d/%d\n",X.Compra.Dia,X.Compra.Mes,X.Compra.ano);
    else
        printf("Não há data de compra.\n");

    if(X.Venda.Dia != -1)
        printf("Venda: %d/%d/%d\n",X.Venda.Dia,X.Venda.Mes,X.Venda.ano);
    else
        printf("Não há data de venda.\n");

    printf("Quantidade: %d\n",X.Quantidade);
    printf("Preço Total: %.2f\n",X.PrecoTotal);
}
ENCOMENDA CriarEncomenda (CLIENTE C, LIVRO L)
{
    time_t now = time(NULL);
    struct tm *pt = localtime(&now);
    ENCOMENDA E;
    E.ISBN = L.ISBN;
    E.NIF = C.NIF;
    E.Encomenda.Dia = pt->tm_mday;
    E.Encomenda.Mes = pt->tm_mon +1;
    E.Encomenda.ano = pt->tm_year +1900;

    E.Compra.Dia = -1;
    E.Venda.Dia = -1;
    printf("\nQuantos quer encomendar? ");
    scanf("%d",&E.Quantidade);
    E.PrecoTotal = E.Quantidade * L.Preco;
    return E;
}
int CompararEncomendas (ENCOMENDA X, ENCOMENDA Y);


/*---------------------------Cliente + funções---------------------------*/

void MostrarCliente (CLIENTE X);
CLIENTE CriarCliente  ();
int CompararClientes (CLIENTE X, CLIENTE Y);