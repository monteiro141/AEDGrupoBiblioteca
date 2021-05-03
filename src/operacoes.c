#include "operacoes.h"

PNodoFila operacao1(PNodoFila Encomendas)
{
    PNodoFila aux=NULL;
    int mesInicial,mesFinal,anoInicial,anoFinal,count=0;
    do
    {
        printf("Introduza um intervalo de tempo válido:\n\n");
        printf("Mês inicial: ");
        scanf("%i",mesInicial);
        printf("Mês final: ");
        scanf("%i",mesFinal);
        printf("Ano inicial: ");
        scanf("%i",anoInicial);
        printf("Ano inicial: ");
        scanf("%i",anoFinal);
    }while (mesInicial <= mesFinal && anoInicial <= anoFinal);
    while(Encomendas!=NULL)
    {
        aux = Inserir(Encomendas->Elemento,aux);
        if(mesInicial <= Encomendas->Elemento.Encomenda.Mes <= mesFinal &&
           anoInicial <= Encomendas->Elemento.Encomenda.ano <= anoFinal)
           {
               count++;
           }
        Encomendas = Remover(Encomendas);
    }
    printf("Foram vendidos %d livros entre %d/%d e %d/%d",count,mesInicial,anoInicial,mesFinal,anoFinal);
    return aux;
}
PNodoFila operacao2(PNodoFila Encomendas)
{
    PNodoFila aux=NULL;
    long long int ISBN;
    int dia=0,mes=0,ano=0;
    printf("Qual é o ISBN?");
    scanf("%lld",&ISBN);
    int dia=0,mes=0,ano=0;
    printf("Dia: ");
    scanf("%i",dia);
    printf("Mês: ");
    scanf("%i",mes);
    printf("Ano: ");
    scanf("%i",ano);
    while(Encomendas!=NULL)
    {
        aux = Inserir(Encomendas->Elemento,aux);
        if(dia < Encomendas->Elemento.Encomenda.Dia && 
           mes < Encomendas->Elemento.Encomenda.Mes &&
           ano < Encomendas->Elemento.Encomenda.ano)
        {
            dia = Encomendas->Elemento.Encomenda.Dia; 
           mes = Encomendas->Elemento.Encomenda.Mes;
           ano = Encomendas->Elemento.Encomenda.ano;
        }
        Encomendas = Remover(Encomendas);
    }
    if(dia==0)
        printf("Não há registo desse livro.\n");
    else
        printf("Ultima compra do livro %lld: %d/%d/%d\n",ISBN,dia,mes,ano);
    return aux;
}

PNodoFila operacao3(PNodoFila Encomendas)
{
    PNodoFila aux=NULL;
    long long int NIF;
    printf("NIF do cliente?");
    scanf("%lld",&NIF);
    int count=0;
    while(Encomendas!=NULL)
    {
        aux = Inserir(Encomendas->Elemento,aux);
        if(Encomendas->Elemento.NIF == NIF)
            count++;
        Encomendas = Remover(Encomendas);
    }
    printf("O cliente com o NIF %d comprou %d livros.\n",NIF,count);
    return aux;
}

void bubbleSort4(LIVRO ** arr, int n)
{
    int i,j;
    LIVRO liv1, liv2;
    LIVRO aux;
    for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if ((*arr)[j].AnoPublicacao > (*arr)[j+1].AnoPublicacao)
           {
            aux = (*arr)[j];
            (*arr)[j] = (*arr)[j+1];
            (*arr)[j+1] = aux;
           }
}
void operacao4Aux(PNodoAB Livros, LIVRO ** kLivros, int * quantidade, char * areaC)
{
    if(Livros==NULL)
        return;
    if(strcmp(Livros->Elemento.AreaCientifica,areaC)==0)
    {
        (*quantidade)++;
        (*kLivros) = realloc((*kLivros),(*quantidade)*sizeof(LIVRO));
        (*kLivros)[(*quantidade)-1] = Livros->Elemento;
    }
    operacao4Aux(Livros->Esquerda,kLivros,quantidade,areaC);
    operacao4Aux(Livros->Direita,kLivros,quantidade,areaC);
}

void operacao4(PNodoAB Livros)
{
    int k=0,quantidade=0,controler=0;
    char areaC[100];
    LIVRO * kLivros = malloc(quantidade*sizeof(LIVRO));
    printf("Area Cientifica?");
    scanf("%[\n]s",areaC);
    printf("Quantos livros?");
    scanf("%d",k);
    operacao4Aux(Livros,&kLivros,&quantidade,areaC);
    bubbleSort4(&kLivros,quantidade);
    for(int i = quantidade;i > 0;i--)
    {
        if(k==controler)
            break;
        MostrarLivro(kLivros[i-1]);
        controler++;
    }
}

