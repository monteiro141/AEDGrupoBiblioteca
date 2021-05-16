#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
//Random
#include "Aleatorio.h"
#include "OperacoesPrimarias.h" 
#include "livrosArvores.h" 
#include "clientesListasLigadas.h" 
#include "encomendasFilas.h"
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
void clearStdinput()
{
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        __fpurge(stdin);
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        fflush(stdin);
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

/*Menu principal que leva para os outros menus.
Começa sempre com os valores das 3 EDs (Estrutura de Dados) a NULL para mais tarde serem usadas*/
int main(void)
{
    livros=NULL;
    clientes=NULL;
    encomendas=NULL;
    int opcao;
    clrscr();
    do
    {
        clearStdinput();
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
    printf("\nOperações disponíveis:\n");
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
    printf("12 - Qual a encomenda mais antiga.\n");
    printf("13 - O cliente com mais encomendas concluidas.\n");
    printf("14 - Dado um livro, quais foram os clientes que o compraram.\n");
    printf("15 - Quantos clientes existem no programa.\n");

    printf("\n");
    printf("0 - Sair do Menu de Operações\n");
    printf("\n");
    printf("Escolha a operação que pretende realizar: ");
}

/*Menu para ler ficheiros
Caso 1 Abrir: Limpar os ficheiros e as EDs no programa
Caso 2 Novo: Limpar as EDs e abrir o conteudo dos ficheiros para o programa
Caso 3 Guardar: Carregar o conteudo do programa para os ficheiros sem sobrepor o que já lá está  */
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
        clearStdinput();
        menuFicheiro();
        scanf("%d",&opcao);
        
        switch(opcao)
        {
            case 1:
            //Limpar o ficheiro
                fpClientes=fopen("EDClientes.bin","wb");
                fpEncomendas=fopen("EDEncomendas.bin","wb");
                fpLivros=fopen("EDLivros.bin","wb");
                clientes = novoClientes(clientes);
                encomendas = novoEncomendas(encomendas);
                livros = novoLivros(livros);
                fclose(fpClientes);
                fclose(fpEncomendas);
                fclose(fpLivros);
                break;

            case 2:
            /*Primeiramente abrimos os ficheiros, limpamos as EDs e copiamos os dados do ficheiro para as EDs
            */
                fpClientes=fopen("EDClientes.bin","rb");
                fpEncomendas=fopen("EDEncomendas.bin","rb");
                fpLivros=fopen("EDLivros.bin","rb");
                clientes = novoClientes(clientes);
                encomendas = novoEncomendas(encomendas);
                livros = novoLivros(livros);
                while(fread(&Cliente,sizeof(CLIENTE),1,fpClientes)==1)
                {
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

/*Menu para ler livros
Caso 1 Inserir: Insere um novo livro na ED livros
Caso 2 Remnover: Remove um livro da ED livros pelo ISBN
Caso 3 Alterar: Remover primeiramente um livro pelo ISBN e depois insere um novo na ED
Caso 4 Consultar: Entra num menu dentro dos livrosArvores.c para consultar os livros */
void lerMenuLivros()
{
    LIVRO livro;
    int opcao;
    int removido;
    clrscr();
    do
    {
        clearStdinput();
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
                removido = 0;
                livros = RemoverLivro(livros,livro,&removido);
                if(removido == 1)
                {
                   encomendas = RemoverPeloISBN(livro.ISBN,encomendas);
                }
                break;

            case 3:
                printf("Qual ISBN para editar?\n");
                scanf("%lld",&livro.ISBN);
                //livros = AlterarLivro(livros,livro,CriarLivro());
                removido = 0;
                if(PesquisarABP(livros,livro)==0)
                    printf("ISBN invalido!\n");
                else
                {
                    livros = RemoverLivro(livros,livro,&removido);
                    livros = InserirLivro(livros,CriarLivro());
                    if(removido == 1)
                    {
                        encomendas = RemoverPeloISBN(livro.ISBN,encomendas);
                    }
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
/*Menu ler clientes
Caso 1 Inserir: Pega no novo cliente e insere no inicio da lista
Caso 2 Remover: Remove o cliente da lista pelo NIF
Caso 3 Alterar: Entra num menu dentro dos clientesListasLigadas.c
Caso 4 Consultar: Entra num menu dentro dos clientesListasLigadas.c*/
void lerMenuClientes()
{
    CLIENTE cliente;
    int opcao;
    clrscr();
    int removido=0;
    do
    {
        clearStdinput();
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
                removido=0;
                clientes = RemoverComNIF(cliente.NIF,clientes,&removido);
                if(removido == 1)
                {
                    encomendas = RemoverPeloNIF(cliente.NIF,encomendas);
                }
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
/*Menu ler encomendas
Caso 1 Inserir: Insere uma nova encomenda se for possivel, pelo ISBN e NIF com uma data e ID dinamicos, decrementando a quantidade em stock do livro
Caso 2 Remover: Remove a encomenda e adiciona ao array do cliente como concluida
Caso 3 Consultar: Entra num menu dentro das encomendas 
*/
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
        clearStdinput();
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
                            livros = AlterarLivro(livros,AUX,L);
                            AUXC = C;
                            clientes = AtualizarCliente(AUXC,C,clientes);
                            encomendas = Inserir(encomenda,encomendas);
                        }
                    }
                }
                break;

            case 2:
                // Remover encomenda e atualizar os clientes
                encRemovida.NIF =-1;
                encomendas = RemoverEncomenda(encomendas,&encRemovida);
                if(encRemovida.NIF!=-1)
                {  

                    ProcurarNIF(encRemovida.NIF,clientes,&C);
                    AUXC = C;
                    C.numeroEncomendas++;
                    encRemovida.Concluida.Dia = pt->tm_mday;
                    encRemovida.Concluida.Mes = pt->tm_mon +1;
                    encRemovida.Concluida.ano = pt->tm_year +1900;
                    C.ListaDeCompras[C.numeroEncomendas-1] = encRemovida;
                    clientes = AtualizarCliente(AUXC,C,clientes);
                }
                break;

            case 3:
                encomendas = ConsultarEncomendas(encomendas);
                break;

            case 0:
                break;
        }
        
    }while(opcao !=0);
}
/*Menu das operacoes*/
void lerMenuOperacoes()
{
    int opcao;
    clrscr();
    do
    {
        clearStdinput();
        menuOperacoes();
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
                /*Quantos livros foram vendidos num dado período de tempo (mês e ano)
                funcao(encomendas) Dentro da função pergunta-se pelo mesinicial-mesfinal e anoinicial-anofinal para contar quantas
                encomendas foram feitas nessa altura*/
                operacao1(clientes);
                break;

            case 2:
                /*funcao2(encomendas);
                Percorre as encomendas e encontra a ultima compra de um dado livro pelo ISBN*/
                operacao2(clientes);
                
                break;

            case 3:
                /*funcao3(encomendas);
                Percorre as encomendas e conta quantos livros um dado cliente (pelo NIF) comprou*/
                operacao3(clientes);
                break;

            case 4:
                /*funcao4(livros)
                Percorre os livros e agrupa-os num array dinamico com a mesma area cientifica que foi dado.
                Após agrupar e, usando um sort, vai mostrar os K livros mais recentes*/
                operacao4(livros);
                break;

            case 5:
                /*funcao5(fila, arvore);
                Dado um mesinicial-mesfinal e anoinicial-anofinal pelo utilizador, percorre a fila de encomendas
                e determina quais foram os livros mais vendidos nesse espaco de tempo
                */
                operacao5(clientes,livros);
                break;

            case 6:
                /*funcao6(arvore);
                Percorre os livros e mostra qual é o livro em maior quantidade numa area cientifica*/
                operacao6(livros);
                break;

            case 7:
                /*funcao7(encomendas,listaClientes);
                Percorre as encomendas e mete num array os clientes com encomendas
                Ao final mostra o que tem mais encomendas*/
                encomendas = operacao7(encomendas,clientes);
                break;

            case 8:
                /*funcao8(listaClientes);
                Percorre os clientes e mostra por ordem decrescente o numero de compras que foram concluidas
                */
                operacao8(clientes);
                break;

            case 9:
                /*funcao9(arvore);
                Percorre os livros e verifica qual foi o ano com mais publicações usando um array dinamico
                */
                operacao9(livros);
                
                break;

            case 10:
                /*funcao10(lista, fila);
                Percorre a lista de clientes e determina qual foi o cliente que mais gastou no total
                */
                encomendas = operacao10(clientes, encomendas);
                break;

            case 11:
                /*funcao(encomendas,clientes,livros)
                Percorre cada ED e conta quantos bytes foram desperdiçados devido ao uso de memoria estática versus memoria dinâmica
                */
                encomendas = operacao11(encomendas,clientes,livros);
                break;
            case 12:
                /*funcao12(fila);
                Percorre a fila de encomendas e determina qual a encomenda mais antiga
                */
                encomendas = operacao12(encomendas);
                break;
            case 13:
                /*funcao13(lista);
                Percorre a lista de clientes e determina qual foi o cliente que possui mais encomendas concluidas
                */
                operacao13(clientes);
                break;
            case 14:
                /*funcao14(arvore, lista, fila);
                Usando um dado livro como referencia, percorre a lista de clientes e mostra
                quais os clientes que compraram o livro em questão
                */
                encomendas = operacao14(livros, clientes, encomendas);
                break;
            case 15:
                /*funcao15(lista, fila);
                Percorre a lista de clientes e mostra todos os clientes que existem
                */
                encomendas = operacao15(clientes, encomendas);
                break;
            case 0:
                break;

            default:
			    printf("Operação inválida, por favor insira um número válido.\n");
        }
        
    }while(opcao !=0);
}