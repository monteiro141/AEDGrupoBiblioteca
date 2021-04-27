#include <stdio.h>
#include <stdlib.h>
//Random
#include "Aleatorio.h"
//#include "OperacoesPrimarias.h" V
//#include "livrosArvores.h" V
//#include "clientesListasLigadas.h" V
#include "encomendasFilas.h"

void menu();
void menuFicheiro();
void menuLivros();
void menuClientes();
void menuEncomendas();
void menuOperacoes();
void lerMenuFicheiro();

PNodoAB livros;
PNodoFila encomendas;


int main(void)
{
    int opcao;
    do
    {
        menu();
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
                lerMenuFicheiro();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                break;
        }
    }while(opcao !=0);


    /*//printf("%d\n",gerarNumeroInteiro(1,100));
    printf("---Teste livro---\n");
    LIVRO L = CriarLivro();
    MostrarLivro(L);
    printf("---Teste cliente---\n");
    CLIENTE C = CriarCliente();
    MostrarCliente(C);
    printf("---Teste encomenda---\n");
    ENCOMENDA E;
    if(CriarEncomenda(C,L,&E)==0)
        MostrarEncomenda(E);
    else
        printf("Não há stock.\n");*/
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
    printf("4 - Sair para o menu.\n");
}
void menuLivros()
{
    printf("1 - Inserir livro.\n");
    printf("2 - Remover(dado ISBN).\n");
    printf("3 - Alterar(dado ISBN).\n");
    printf("4 - Consultar por ISBN.\n");
    printf("5 - Consultar por Titulo.\n");
    printf("6 - Consultar por Autor.\n");
    printf("7 - Consultar por Editora.\n");
    printf("8 - Consultar por Area Cientifica.\n");
}
void menuClientes()
{
    printf("1 - Inserir cliente.\n");
    printf("2 - Remover(dado NIF).\n");
    printf("3 - Alterar(dado NIF).\n");
    printf("4 - Consultar por NIF.\n");
    printf("5 - Consultar por Nome.\n");
    printf("6 - Consultar por Morada.\n");
}
void menuEncomendas()
{
    printf("1 - Inserir encomenda.\n");
    printf("2 - Remover (implica atualização da lista de compras do Cliente).\n");
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

void menuFicheiro()
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
                    printf("Porfazer.\n");
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

                fclose(fpClientes);
                fclose(fpEncomendas);
                fclose(fpLivros);
                break;

            case 4:
                break;
        }
    }while(opcao !=4);
}