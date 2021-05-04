#include <stdio.h>
#include <stdlib.h>
//Random
#include "Aleatorio.h"
//#include "OperacoesPrimarias.h" V
//#include "livrosArvores.h" V
//#include "clientesListasLigadas.h" V
//#include "encomendasFilas.h"
#include "operacoes.h"

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
void lerMenuEncomendas();
void lerMenuOperacoes();

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
                lerMenuEncomendas();
                break;
            case 5:
                lerMenuOperacoes();
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
    printf("2 - Remover.\n");
    printf("3 - Consultar todas.\n");
    printf("0 - Sair para o menu.\n");
}
void menuOperacoes()
{
    printf("Operações disponíveis:\n");
    printf("\n");
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
    printf("\n");
    printf("0 - Sair do Menu de Operações\n");
    printf("\n");
    printf("Escolha a operação que pretende realizar: ");
}

//Por acabar
void lerMenuFicheiro()
{
    CLIENTE Cliente;
    ENCOMENDA Encomenda;
    LIVRO Livro;

    int opcao;
    FILE * fpClientes=NULL,*fpEncomendas=NULL,*fpLivros=NULL;
    clrscr();
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
                    //MostrarCliente(Cliente);
                    clientes = InserirInicio(Cliente,clientes);
                }
                while(fread(&Encomenda,sizeof(ENCOMENDA),1,fpEncomendas)==1)
                {
                    encomendas = Inserir(Encomenda,encomendas);
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
                guardarClientes(clientes,fpClientes);
                encomendas = guardarEncomendas(encomendas,fpEncomendas);
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
    clrscr();
    do
    {
        menuLivros();
        scanf("%d",&opcao);
       
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
                //livros = AlterarLivro(livros,livro,CriarLivro());
                if(PesquisarABP(livros,livro)==0)
                    printf("ISBN invalido!\n");
                else
                {
                    livros = RemoverLivro(livros,livro);
                    livros = InserirLivro(livros,CriarLivro());
                }
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
    clrscr();
    do
    {
        menuClientes();
        scanf("%d",&opcao);
        
        switch(opcao)
        {
            case 1:
                clientes = InserirInicio(CriarCliente(),clientes);
                break;

            case 2:
                printf("Qual NIF para remover?\n");
                scanf("%lld",&cliente.NIF);
                clientes = RemoverComNIF(cliente.NIF,clientes);
                //fazer o remover encomenda pelo NIF
                break;

            case 3:
                clientes = AlterarComNIF(clientes);
                break;

            case 4:
                encomendas = ConsultarClientesPor(clientes,encomendas);
                break;

            case 0:
                break;
        }
        
    }while(opcao !=0);
}

void lerMenuEncomendas()
{
    ENCOMENDA encomenda;
    LIVRO L,AUX;
    CLIENTE C,AUXC;
    ENCOMENDA encRemovida;
    time_t now = time(NULL);
    struct tm *pt = localtime(&now);
    int qtd;
    int opcao;
    clrscr();
    do
    {
        menuEncomendas();
        scanf("%d",&opcao);
        
        switch(opcao)
        {
            case 1:
                printf("NIF do cliente: ");
                scanf("%lld",&C.NIF);
                if(ProcurarNIF(C.NIF,clientes,&C)==1)
                    printf("Não existe esse cliente!\n");
                else
                {
                    C = DevolveCliente(C,clientes);
                    printf("ISBN do livro: ");
                    scanf("%lld",&L.ISBN);
                    
                    if(PesquisarABP(livros,L) == 0 )
                        printf("Não existe esse livro.\n");
                    else {
                        L = DevolveLivro(livros,L);
                        if((qtd = CriarEncomenda(C,L,&encomenda,&encomendas))==-1)
                            printf("Não foi possivel criar a encomenda.\n");
                        else
                        {
                            AUX = L;
                            L.QuantidadeStock -= qtd;
                            //printf("Antes do altLivro.\n");
                            livros = AlterarLivro(livros,AUX,L);
                            //printf("Depois do altLivro.\n");
                            AUXC = C;
                            //C.numeroEncomendas++;
                            clientes = AtualizarCliente(AUXC,C,clientes);
                            encomendas = Inserir(encomenda,encomendas);
                        }
                    }
                }
                break;

            case 2:
                // Remover encomenda e atualizar os clientes
                encomendas = RemoverEncomenda(encomendas,&encRemovida);
                ProcurarNIF(C.NIF,clientes,&C);
                AUXC = C;
                C.numeroEncomendas++;
                encRemovida.Concluida.Dia = pt->tm_mday;
                encRemovida.Concluida.Mes = pt->tm_mon +1;
                encRemovida.Concluida.ano = pt->tm_year +1900;
                C.ListaDeCompras[C.numeroEncomendas-1] = encRemovida;
                clientes = AtualizarCliente(AUXC,C,clientes);
                break;

            case 3:
                encomendas = ConsultarEncomendas(encomendas);
                break;

            case 0:
                break;
        }
        
    }while(opcao !=0);
}

void lerMenuOperacoes()
{
    int opcao;
    clrscr();
    do
    {
        menuOperacoes();
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
                /*Quantos livros foram vendidos num dado período de tempo (mês e ano)
                funcao1(filas, mes1, mes2, ano1, ano2); livros -> arvore ; encomendas -> filas tem as datas
                Buscar os ISBNs à função e listar pelo void ConsultarLivroISBN(PNodoAB t, int ISBN)
                percorrer a arvore e conta quantos livros foram vendidos
                entre 'x' e 'y' meses dentro de 'a' e 'b' anos*/
                encomendas = operacao1(encomendas);
                break;

            case 2:
                /*funcao2(encomendas, livro);
                percorre as encomendas dentro da arvore
                e guarda a data mais recente do 'livro' vendido escolhido*/
                
                encomendas = operacao2(encomendas);
                
                break;

            case 3:
                //funcao3(cliente,encomendas);
                
                // percorrer todas as encomendas e somar a 'Quantidade'
                encomendas = operacao3(encomendas);
                break;

            case 4:
                /*funcao4(arvore,area cientifica, int K)
                percorrer a arvore e comparar os Nodos a procura de livros da 'area cientifica'
                e por os livros da 'area cientifica' por ordem crescente
                (os mais recentes primeiro)
                mostrar os K primeiro elementos*/
                operacao4(livros);
                break;

            case 5:
                //funcao5(fila encomendas, mes1, mes2, ano1, ano2, int K);
                encomendas = operacao5(encomendas,livros);
                // similar a funcao4, mas tem em conta os intervalos de tempo
                // em vez da 'Area Cientifica'
                break;

            case 6:
                //funcao6(arvore);
                operacao6(livros);
                // procurar a arvore pelos diferentes tipos de 'Areas Cientificas'
                // e conta a quantidade de livros de cada categoria
                break;

            case 7:
                //funcao7(listaClientes);
                encomendas = operacao7(operacao7,clientes);
                // usa a funcao3 ate nao haver mais clientes para analisar, 
                // guardando o cliente e o numero de livros comprados,
                // comparando-os e mantemdo o cliente com o maior numero de livros comprado
                break;

            case 8:
                //funcao8(listaClientes);

                // similarmente a funcao7, usa a funcao3 e guarda todos os clientes
                // com o numero de livros comprados numa lista
                // e de seguida e ordenado com um algoritmo de ordenacao
                break;

            case 9:
                //funcao9(arvore);
                operacao9(livros);
                // percorrer a arvore e encontrar o ano mais antigo de publicacao
                // apos encontrar o numero mais antigo percorrer a arvore toda ate ao ano atual
                // guardando o numero de livros publicados no ano em questao para comparar com o ano a seguir
                // guardando o ano com mais publicacoes
                break;

            case 10:
                //funcao10(listaClientes, mes1, mes2, ano1, ano2, encomendas);

                // percorrer a listaClientes e le o precoTotal das encomendas de cada cliente,
                // comparando-o com o seguinte, guardando apenas o cliente com o maior gasto
                break;

            case 11:
                //funcao11();

                // nao faco a minima como pegar nisto 991 sirene
                break;
            case 0:
                break;

            default:
			    printf("Operação inválida, por favor insira um número válido.\n");
        }
        
    }while(opcao !=0);
}