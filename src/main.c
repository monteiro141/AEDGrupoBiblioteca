#include <stdio.h>
#include <stdlib.h>
//Random
#include "Aleatorio.h"
//#include "OperacoesPrimarias.h" V
//#include "livrosArvores.h" V
//#include "clientesListasLigadas.h" V
#include "encomendasFilas.h"

//Mostrar os menus
void clrscr()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}
void menu();
void menuFicheiro();
void menuLivros();
void menuClientes();
void menuEncomendas();
void menuOperacoes();
//Executar operaçoes sobre os menus
void lerMenuFicheiro();
void lerMenuLivros();
void lerMenuClientes();

PNodoAB livros;
PNodo clientes;
PNodoFila encomendas;


int main(void)
{
    livros=NULL;
    clientes=NULL;
    encomendas=NULL;
    int opcao;
    clrscr();
    do
    {
        
        menu();
        scanf("%d",&opcao);
        clrscr();
        switch(opcao)
        {
            case 1:
                lerMenuFicheiro();
                break;
            case 2:
                lerMenuLivros();
                break;
            case 3:
                lerMenuClientes();
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                break;
        }
    }while(opcao !=0);
    return 0;
}

void menu()
{
    printf("1 - Ficheiro.\n");
    printf("2 - Livros.\n");
    printf("3 - Clientes.\n");
    printf("4 - Encomendas.\n");
    printf("5 - Operações.\n");
    printf("0 - Sair.\n");
}
void menuFicheiro()
{
    printf("1 - Novo (criar um ED nova - vazia).\n");
    printf("2 - Abrir (passar os dados de um ficheiro para a ED).\n");
    printf("3 - Guardar (passar da ED para o ficheiro corrente).\n");
    printf("0 - Sair para o menu.\n");
}
void menuLivros()
{
    printf("1 - Inserir livro.\n");
    printf("2 - Remover(dado ISBN).\n");
    printf("3 - Alterar(dado ISBN).\n");
    printf("4 - Consultar.\n");
    printf("0 - Sair para o menu.\n");
}
void menuClientes()
{
    printf("1 - Inserir cliente.\n");
    printf("2 - Remover(dado NIF).\n");
    printf("3 - Alterar(dado NIF).\n");
    printf("4 - Consultar.\n");
    printf("0 - Sair para o menu.\n");
}
void menuEncomendas()
{
    printf("1 - Inserir encomenda.\n");
    printf("2 - Remover (implica atualização da lista de compras do Cliente).\n");
    printf("0 - Sair para o menu.\n");
}
void menuOperacoes()
{
    printf("1 - Quantos livros foram vendidos num dado período de tempo (mês e ano).\n");
    printf("2 - Determinar a data da última compra/venda de um dado livro.\n");
    printf("3 - Determinar quantos livros um dado cliente já comprou.\n");
    printf("4 - Mostrar os K livros mais recentes de uma dada Área Científica.\n");
    printf("5 - Mostrar os K livros mais vendidos num dado período (mês e ano).\n");
    printf("6 - Determinar a Área Científica com mais livros.\n");
    printf("7 - Determinar qual o Cliente com mais livros comprados.\n");
    printf("8 - Mostrar os Clientes por ordem decrescente do número de compras.\n");
    printf("9 - Determinar o Ano com mais publicações.\n");
    printf("10 - Calcular o cliente que mais gastou num dado período (mês e ano).\n");
    printf("11 - Determinar o desperdício de memória.\n");
}

//Por acabar
void lerMenuFicheiro()
{
    CLIENTE Cliente;
    ENCOMENDA Encomenda;
    LIVRO Livro;

    int opcao;
    FILE * fpClientes=NULL,*fpEncomendas=NULL,*fpLivros=NULL;
    do
    {
        menuFicheiro();
        scanf("%d",&opcao);
        clrscr();
        switch(opcao)
        {
            case 1:
            //Limpar o ficheiro
                fpClientes=fopen("EDClientes.bin","wb");
                fpEncomendas=fopen("EDEncomendas.bin","wb");
                fpLivros=fopen("EDLivros.bin","wb");
                fclose(fpClientes);
                fclose(fpEncomendas);
                fclose(fpLivros);
                break;

            case 2:
            //Ler de files para C
                fpClientes=fopen("EDClientes.bin","rb");
                fpEncomendas=fopen("EDEncomendas.bin","rb");
                fpLivros=fopen("EDLivros.bin","rb");
                while(fread(&Cliente,sizeof(CLIENTE),1,fpClientes)==1)
                {
                    //INSERIR CLIENTE
                    //printf("Porfazer.\n");
                    clientes = InserirInicio(Cliente,clientes);
                }
                while(fread(&Encomenda,sizeof(ENCOMENDA),1,fpEncomendas)==1)
                {
                    //INSERIR encomenda
                    printf("Porfazer.\n");

                }
                while(fread(&Livro,sizeof(LIVRO),1,fpLivros)==1)
                {
                    livros = InserirLivro(livros,Livro);
                }
                fclose(fpClientes);
                fclose(fpEncomendas);
                fclose(fpLivros);
                break;

            case 3:
            //Ler do C para files
                fpClientes=fopen("EDClientes.bin","wb");
                fpEncomendas=fopen("EDEncomendas.bin","wb");
                fpLivros=fopen("EDLivros.bin","wb");
                
                guardarLivros(livros,fpLivros);
                guarderClientes(clientes,fpClientes);

                fclose(fpClientes);
                fclose(fpEncomendas);
                fclose(fpLivros);
                break;

            case 0:
                break;
        }
    }while(opcao !=0);
}

void lerMenuLivros()
{
    LIVRO livro;
    int opcao;
    do
    {
        menuLivros();
        scanf("%d",&opcao);
        clrscr();
        switch(opcao)
        {
            case 1:
                livros = InserirLivro(livros,CriarLivro());
                break;

            case 2:
                printf("Qual ISBN para remover?\n");
                scanf("%lld",&livro.ISBN);
                livros = RemoverLivro(livros,livro);
                break;

            case 3:
                printf("Qual ISBN para editar?\n");
                scanf("%lld",&livro.ISBN);
                livros = AlterarLivro(livros,livro,CriarLivro());
                break;

            case 4:
                ConsultarLivro(livros);
                break;

            case 0:
                break;
        }
        
    }while(opcao !=0);
    
}

void lerMenuClientes()
{
    CLIENTE cliente;
    int opcao;
    do
    {
        menuClientes();
        scanf("%d",&opcao);
        clrscr();
        switch(opcao)
        {
            case 1:
                clientes = InserirInicio(CriarCliente(),clientes);
                break;

            case 2:
                printf("Qual NIF para remover?\n");
                scanf("%lld",&cliente.NIF);
                clientes = RemoverComNIF(cliente.NIF,clientes);
                break;

            case 3:
                clientes = AlterarComNIF(clientes);
                break;

            case 4:
                ConsultarClientesPor(clientes);
                break;

            case 0:
                break;
        }
        
    }while(opcao !=0);
}

