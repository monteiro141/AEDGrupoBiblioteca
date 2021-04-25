/*---------------------------Data---------------------------*/
/*
Data: Contêm apenas Dia, Mes e Ano.
*/
typedef struct 
{
    int Dia;
    int Mes;
    int ano;
} DATADMA;

typedef struct LIVRO
{
    long long int ISBN;
    char Titulo[100];
    char Idioma[100];
    char PrimeiroAutor[100];
    char SegundoAutor[100];
    char Editora[100];
    int AnoPublicacao;
    char AreaCientifica[100];
    float Preco;
    int QuantidadeStock;
} LIVRO;

typedef struct ENCOMENDA
{
    long long int ISBN;
    long long int NIF;
    DATADMA Encomenda;
    int Quantidade;
    float PrecoTotal;
}ENCOMENDA;

typedef struct CLIENTE
{
    long long int NIF;
    char Nome[100];
    char Morada[100];
    long long int Telefone;
    ENCOMENDA * ListaDeCompras;
    int numeroEncomendas;
}CLIENTE;



/*---------------------------Livro + Funções---------------------------*/
/*
Livro:ISBN, Título, Idioma, Primeiro Autor, Segundo Autor, Editora, Ano de Publicação, Área Científica (Matemática, Física, Química,
        Programação, Informática, Processamento Digital, Sistemas Digitais, Base de Dados, ...), Preço (euros) e Quantidade em “stock”.
Funções:MostrarLivro(Recebe um Livro X e mostra os atributos todos do livro, não devolve)
        CriarLivro(Cria um livro modo random e devolve um livro)
        CompararLivros(Recebe livro X e Y, devolve 0 se forem iguais, -1 se x < y e 1 se x > y).
*/

void MostrarLivro (LIVRO X);
LIVRO CriarLivro ();
int CompararLivros (LIVRO X, LIVRO Y);


/*---------------------------Encomenda + funções---------------------------*/
/*
Encomenda:Livro (ISBN), Cliente (NIF), Data de encomenda/compra/venda, Número de unidades encomendadas e Preço total.
Funções:MostrarEncomenda(Recebe uma Encomenda X e mostra os atributos todos da Encomenda, não devolve)
        CriarEncomenda(Cria uma Encomenda modo random e devolve uma Encomenda)
        CompararEncomendas(Recebe Encomenda X e Y, devolve 0 se forem iguais, -1 se x < y e 1 se x > y).
*/

void MostrarEncomenda (ENCOMENDA E);
int CriarEncomenda (CLIENTE C, LIVRO L,ENCOMENDA * E);
int CompararEncomendas (ENCOMENDA X, ENCOMENDA Y);


/*---------------------------Cliente + funções---------------------------*/
/*
Encomenda:NIF, Nome, Morada, Telefone e Lista de compras efetuadas.
Funções:MostrarCliente(Recebe um Cliente X e mostra os atributos todos do Cliente, não devolve)
        CriarCliente(Cria um Cliente modo random e devolve um Cliente)
        CompararClientes(Recebe Cliente X e Y, devolve 0 se forem iguais, -1 se x < y e 1 se x > y).
*/

void MostrarCliente (CLIENTE C);
CLIENTE CriarCliente();
int CompararClientes (CLIENTE X, CLIENTE Y);