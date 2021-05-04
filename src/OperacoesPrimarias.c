#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "OperacoesPrimarias.h"

/*---------------------------Livro + Funções---------------------------*/
void MostrarLivro (LIVRO X)
{
    printf("################################\n");
    printf("ISBN: %lld\n",X.ISBN);
    printf("Titulo: %s.\n",X.Titulo);
    printf("Primeiro Autor: %s.\n",X.PrimeiroAutor);
    printf("Segundo Autor: %s.\n",X.SegundoAutor);
    printf("Editora: %s.\n",X.Editora);
    printf("Ano Publicacao: %d.\n",X.AnoPublicacao);
    printf("Area Cientifica: %s.\n",X.AreaCientifica);
    printf("Preco: %.2f.\n",X.Preco);
    printf("Quantidade em stock: %d.\n",X.QuantidadeStock);
    printf("################################\n");
}
LIVRO CriarLivro ()
{
    LIVRO x;
    printf("################################\n");
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
    printf("################################\n");
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
    printf("**\n");
    printf("ID: %d.\n",E.ID);
    printf("ISBN: %lld.\n",E.ISBN);
    printf("NIF: %lld.\n",E.NIF);
    printf("Quantidade: %d\n",E.Quantidade);
    printf("Preço Total: %.2f\n",E.PrecoTotal);
    printf("Encomenda: %d/%d/%d\n",E.Encomenda.Dia,E.Encomenda.Mes,E.Encomenda.ano);
    if(E.Concluida.ano==-1)
        printf("Não foi concluida\n");
    else
        printf("Concluida: %d/%d/%d\n",E.Concluida.Dia,E.Concluida.Mes,E.Concluida.ano);
    printf("**\n");
}

int CriarEncomenda (CLIENTE C, LIVRO L,ENCOMENDA * E, PNodoFila * encomendas)
{
    int n=0;
    time_t now = time(NULL);
    struct tm *pt = localtime(&now);
    printf("################################\n");
    printf("\nQuantos quer encomendar? ");
    scanf("%d",&n);
    PNodoFila aux = NULL;
    ENCOMENDA Enc;
    Enc.ID=0;
    if(n <= L.QuantidadeStock)
    {
        while(*encomendas!=NULL)
        {
            aux = Inserir((*encomendas)->Elemento,aux);
            Enc.ID = (*encomendas)->Elemento.ID;
            (*encomendas) = Remover((*encomendas));
        }
        (*E).ID = Enc.ID + 1;
        (*E).ISBN = L.ISBN;
        (*E).NIF = C.NIF;
        (*E).Encomenda.Dia = pt->tm_mday;
        (*E).Encomenda.Mes = pt->tm_mon +1;
        (*E).Encomenda.ano = pt->tm_year +1900;
        (*E).Quantidade = n;
        (*E).Concluida.Dia = -1;
        (*E).Concluida.Mes = -1;
        (*E).Concluida.ano = -1;
        (*E).PrecoTotal = (*E).Quantidade * L.Preco;

        while(aux!=NULL)
        {
            (*encomendas) = Inserir(aux->Elemento,(*encomendas));
            Enc.ID = (*encomendas)->Elemento.ID;
            aux = Remover(aux);
        }
        return n;
    }
    printf("################################\n");
    return -1;
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

PNodoFila MostrarCliente (CLIENTE C,PNodoFila Fila)
{
    printf("################################\n");
    printf("NIF: %lld.\n",C.NIF);
    printf("Nome: %s.\n",C.Nome);
    printf("Morada: %s.\n",C.Morada);
    printf("Telefone: %lld.\n",C.Telefone);
    printf("\n***Encomendas concluidas***\n");
    for(int i = 0; i < C.numeroEncomendas; i++)
    {
        MostrarEncomenda(C.ListaDeCompras[i]);
    }
    printf("\n***Encomendas por concluir***\n");
    Fila = mostrarPorCliente(Fila,C);
    printf("################################\n");
    return Fila;
}
CLIENTE CriarCliente()
{
    printf("################################\n");
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
    //C.ListaDeCompras = malloc(C.numeroEncomendas*sizeof(ENCOMENDA));
    printf("################################\n");
    return C;
}
int CompararClientes (CLIENTE X, CLIENTE Y)
{
    if(X.NIF > Y.NIF)
        return 1;
    else if(X.NIF < Y.NIF)
        return -1;
    else
        return 0;
}