/*---------------------------Data---------------------------*/
/*
Data: Contêm apenas Dia, Mes e Ano.
*/
typedef struct 
{
    int Dia;
    int Mes;
    int ano;
} DATA;

/*---------------------------Livro + Funções---------------------------*/
/*
Livro:ISBN, Título, Idioma, Primeiro Autor, Segundo Autor, Editora, Ano de Publicação, Área Científica (Matemática, Física, Química,
        Programação, Informática, Processamento Digital, Sistemas Digitais, Base de Dados, ...), Preço (euros) e Quantidade em “stock”.
Funções:MostrarLivro(Recebe um Livro X e mostra os atributos todos do livro, não devolve)
        CriarLivro(Cria um livro modo random e devolve um livro)
        CompararLivros(Recebe livro X e Y, devolve 1 se forem iguais e 0 se forem diferentes).
*/
typedef struct 
{
    double ISBN;
    char Titulo[100];
    char Idioma[100];
    char PrimeiroAutor[100];
    char SegundoAutor[100];
    char Editora[100];
    int AnoPublicacao;
    char AreaCientifica[100];
    float Preco;
    int Quantidade;
} LIVRO;
void MostrarLivro (LIVRO X);
LIVRO CriarLivro ();
int CompararLivros (LIVRO X, LIVRO Y);


/*---------------------------Encomenda + funções---------------------------*/
/*
Encomenda:Livro (ISBN), Cliente (NIF), Data de encomenda/compra/venda, Número de unidades encomendadas e Preço total.
Funções:MostrarEncomenda(Recebe uma Encomenda X e mostra os atributos todos da Encomenda, não devolve)
        CriarEncomenda(Cria uma Encomenda modo random e devolve uma Encomenda)
        CompararEncomendas(Recebe Encomenda X e Y, devolve 1 se forem iguais e 0 se forem diferentes).
*/
typedef struct
{
    int ISBN;
    int NIF;
    DATA Encomenda;
    DATA Compra;
    DATA Venda;
    int Quantidade;
    float PrecoTotal;
}ENCOMENDA;

void MostrarEncomenda (ENCOMENDA X);
ENCOMENDA CriarEncomenda ();
int CompararEncomendas (ENCOMENDA X, ENCOMENDA Y);


/*---------------------------Cliente + funções---------------------------*/
/*
Encomenda:NIF, Nome, Morada, Telefone e Lista de compras efetuadas.
Funções:MostrarCliente(Recebe um Cliente X e mostra os atributos todos do Cliente, não devolve)
        CriarCliente(Cria um Cliente modo random e devolve um Cliente)
        CompararClientes(Recebe Cliente X e Y, devolve 1 se forem iguais e 0 se forem diferentes).
*/
typedef struct
{
    int NIF;
    char Nome[100];
    char Morada[100];
    int Telefone;
    ENCOMENDA * ListaDeCompras;
}CLIENTE;

void MostrarCliente (CLIENTE X);
CLIENTE CriarCliente  ();
int CompararClientes (CLIENTE X, CLIENTE Y);