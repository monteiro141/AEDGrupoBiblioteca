#include "operacoes.h"

PNodoFila operacao1(PNodoFila Encomendas)
{
    PNodoFila aux=NULL;
    int mesInicial,mesFinal,anoInicial,anoFinal,count=0;
    do
    {
        printf("Introduza um intervalo de tempo válido:\n\n");
        printf("Mês inicial: ");
        scanf("%i",&mesInicial);
        printf("Mês final: ");
        scanf("%i",&mesFinal);
        printf("Ano inicial: ");
        scanf("%i",&anoInicial);
        printf("Ano inicial: ");
        scanf("%i",&anoFinal);
    }while (mesInicial <= mesFinal && anoInicial <= anoFinal);
    while(Encomendas!=NULL)
    {
        aux = Inserir(Encomendas->Elemento,aux);
        if(mesInicial <= Encomendas->Elemento.Encomenda.Mes && Encomendas->Elemento.Encomenda.Mes <= mesFinal &&
           anoInicial <= Encomendas->Elemento.Encomenda.ano && Encomendas->Elemento.Encomenda.ano <= anoFinal)
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
    printf("Dia: ");
    scanf("%i",&dia);
    printf("Mês: ");
    scanf("%i",&mes);
    printf("Ano: ");
    scanf("%i",&ano);
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
    printf("O cliente com o NIF %lld comprou %d livros.\n",NIF,count);
    return aux;
}

void bubbleSort4(LIVRO ** arr, int n)
{
    int i,j;
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
    printf("E-> %s | AC %s\n",Livros->Elemento.AreaCientifica,areaC);
    if(strstr(Livros->Elemento.AreaCientifica,areaC)!=NULL)
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
    int k=0,quantidade=0;
    char areaC[100];
    LIVRO * kLivros = malloc(quantidade*sizeof(LIVRO));
    printf("Area Cientifica?");
    scanf("\n%[^\n]s",areaC);
    printf("Quantos livros?");
    scanf("%d",&k);
    operacao4Aux(Livros,&kLivros,&quantidade,areaC);
    bubbleSort4(&kLivros,quantidade);
    for(int i = 0;i < k && i < quantidade ;i++)
    {
        MostrarLivro(kLivros[i]);
    }
    free(kLivros);
}

void bubbleSort5(operacao5Counter ** arr, int n)
{
    int i,j;
    operacao5Counter aux;
    for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if ((*arr)[j].qtd < (*arr)[j+1].qtd)
           {
            aux = (*arr)[j];
            (*arr)[j] = (*arr)[j+1];
            (*arr)[j+1] = aux;
           }
}

PNodoFila operacao5Aux(PNodoFila ENCOMENDA,int mI,int mF,int aI,int aF,operacao5Counter ** kLivros,int * quantidade)
{
    PNodoFila aux=NULL;
    int exist=0;
    while(ENCOMENDA !=NULL)
    {   
        aux = Inserir(ENCOMENDA->Elemento,aux);
        if(mI<=ENCOMENDA->Elemento.Encomenda.Mes && ENCOMENDA->Elemento.Encomenda.Mes <= mF &&
           aI<=ENCOMENDA->Elemento.Encomenda.ano && ENCOMENDA->Elemento.Encomenda.ano <= aF)
           {
                for(int i = 0;i< (*quantidade);i++)
                {
                    if((*kLivros)[i].ISBN==ENCOMENDA->Elemento.ISBN)
                    {
                        (*kLivros)[i].qtd += ENCOMENDA->Elemento.Quantidade;
                        exist=1;
                    }
                }
                if(exist==0)
                {
                    (*quantidade)++;
                    (*kLivros)= realloc((*kLivros),(*quantidade)*sizeof(operacao5Counter));
                    (*kLivros)[(*quantidade)-1].ISBN = ENCOMENDA->Elemento.ISBN;
                    (*kLivros)[(*quantidade)-1].qtd = ENCOMENDA->Elemento.Quantidade;
                    exist=0;
                }
           }
        ENCOMENDA = Remover(ENCOMENDA);
    }
    return aux;
}

PNodoFila operacao5(PNodoFila ENCOMENDA, PNodoAB LIVROS)
{
    int k=0,mesInicial=0,mesFinal=0,anoInicial=0,anoFinal=0,quantidade=0;
    operacao5Counter * kLivros = malloc(quantidade*sizeof(operacao5Counter));
    printf("Quantos livros?");
    scanf("%d",&k);
    printf("Mes inicial?");
    scanf("%d",&mesInicial);
    printf("Mes final?");
    scanf("%d",&mesFinal);
    printf("Ano inicial?");
    scanf("%d",&anoInicial);
    printf("Ano final?");
    scanf("%d",&anoFinal);
    ENCOMENDA = operacao5Aux(ENCOMENDA,mesInicial,mesFinal,anoInicial,anoFinal,&kLivros,&quantidade);
    bubbleSort5(&kLivros,quantidade);
    for(int i = 0;i < k && i < quantidade ;i++)
    {
        printf("\nVendidos: %d\n",kLivros[i].qtd);
        ConsultarLivroISBN(LIVROS,kLivros[i].ISBN);
    }
    free(kLivros);
    return ENCOMENDA;
}


void bubbleSort6(operacao6counter ** arr, int n)
{
    int i,j;
    operacao6counter aux;
    for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if ((*arr)[j].qtd < (*arr)[j+1].qtd)
           {
            aux = (*arr)[j];
            (*arr)[j] = (*arr)[j+1];
            (*arr)[j+1] = aux;
           }
}

void operacao6Aux(PNodoAB LIVROS, operacao6counter ** livrosAC,int * quantidade)
{
    int exist=0;
    if(LIVROS == NULL)
        return;
    for(int i=0;i < (*quantidade);i++)
    {
        if(strcmp(LIVROS->Elemento.AreaCientifica,(*livrosAC)[i].AreaCientifica)==0)
        {
            exist=1;
            (*livrosAC)[i].qtd++;
        }
    }
    if(exist==0)
    {
        (*quantidade)++;
        (*livrosAC)= realloc((*livrosAC),(*quantidade)*sizeof(operacao6counter));
        strcpy((*livrosAC)[(*quantidade)-1].AreaCientifica,LIVROS->Elemento.AreaCientifica);
        (*livrosAC)[(*quantidade)-1].qtd=1;
    }
    operacao6Aux(LIVROS->Esquerda, livrosAC,quantidade);
    operacao6Aux(LIVROS->Direita, livrosAC,quantidade);
    return;
}
void operacao6(PNodoAB LIVROS)
{
    int quantidade=0;
    operacao6counter * livrosAC = malloc(quantidade*sizeof(operacao6counter));
    operacao6Aux(LIVROS,&livrosAC,&quantidade);
    bubbleSort6(&livrosAC,quantidade);
    if(quantidade>=1)
    {
        printf("Area Cientifica: %s.\n",livrosAC[0].AreaCientifica);
        printf("Quantidade: %d\n",livrosAC[0].qtd);
    }else
    {
        printf("Não tem livros.\n");
    }
    free(livrosAC);
    return;
}

void bubbleSort7(operacao7counter ** arr, int n)
{
    int i,j;
    operacao7counter aux;
    for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if ((*arr)[j].qtdLivros < (*arr)[j+1].qtdLivros)
           {
            aux = (*arr)[j];
            (*arr)[j] = (*arr)[j+1];
            (*arr)[j+1] = aux;
           }
}

PNodoFila operacao7Aux(PNodoFila ENCOMENDAS,operacao7counter ** clientes,int * quantidade)
{
    PNodoFila aux=NULL;
    int exist=0;
    while(ENCOMENDAS != NULL)
    {
        aux = Inserir(ENCOMENDAS->Elemento,aux);
        for(int i=0;i < (*quantidade);i++)
        {
            if(ENCOMENDAS->Elemento.NIF==(*clientes)[i].NIF)
            {
                exist=1;
                (*clientes)[i].qtdLivros += ENCOMENDAS->Elemento.Quantidade;
            }
        }
        if(exist==0)
        {
            (*quantidade)++;
            (*clientes) = realloc((*clientes),(*quantidade)*sizeof(operacao7counter));
            (*clientes)[(*quantidade)-1].NIF = ENCOMENDAS->Elemento.NIF;
            (*clientes)[(*quantidade)-1].qtdLivros = ENCOMENDAS->Elemento.Quantidade;
        }
    }
    return aux;
}

PNodoFila operacao7(PNodoFila ENCOMENDAS, PNodo L)
{
    int quantidade=0;
    operacao7counter * clientes = malloc(quantidade*sizeof(operacao7counter));
    ENCOMENDAS = operacao7Aux(ENCOMENDAS,&clientes,&quantidade);
    bubbleSort7(&clientes,quantidade);
    if(quantidade==0)
        printf("Não há clientes com encomendas.\n");
    else
        ENCOMENDAS = ConsultarClientesPorNIF(clientes[0].NIF,L,ENCOMENDAS);
    return ENCOMENDAS;
}

void operacao8(PNodo listaClientes)
{
    PNodo aux = listaClientes;
    int tamanhototalclientes = 1, exists = 0;
    operacao8cliente * clientes = malloc(tamanhototalclientes*sizeof(operacao8cliente));

    while (aux != NULL)
    {
        for (int i = 0; i < tamanhototalclientes; i++)
        {
            if (aux->Elemento.NIF == clientes[tamanhototalclientes-1].NIF)
            {
                exists=1;
            }
        
            if (exists == 0)
            {
                
                tamanhototalclientes++;
                clientes= realloc(clientes, tamanhototalclientes*sizeof(operacao8cliente));

                operacao8cliente novoCliente;
                novoCliente.NIF = aux->Elemento.NIF;
                strcpy(novoCliente.Nome, aux->Elemento.Nome);
                novoCliente.numeroCompras = aux->Elemento.numeroEncomendas;
                clientes[tamanhototalclientes-1] = novoCliente;
            }
            exists=0;
        }
        aux = aux->Prox;
    }

    int i,j;
    operacao8cliente clienteAux;
    for (i = 0; i < tamanhototalclientes-1; i++)      
    {
        // Last i elements are already in place   
        for (j = 0; j < tamanhototalclientes-i-1; j++) 
        {
            if (clientes[j].numeroCompras > clientes[j+1].numeroCompras)
            {
                clienteAux = clientes[j];
                clientes[j] = clientes[j+1];
                clientes[j+1] = clienteAux;
            }
        }
    }

    for (int i = 0; i < tamanhototalclientes; i++)
    {
        printf("NIF: %lld, Nome: %s, Número de encomendas: %i", clientes[i].NIF, clientes[i].Nome, clientes[i].numeroCompras);
    }
}


void operacao9Aux(PNodoAB LIVROS, operacao9counter ** livrosAnoPub,int * quantidade)
{
    if(LIVROS == NULL)
        return;
    int exist=0;
    for(int i=0;i < (*quantidade);i++)
    {
        if(LIVROS->Elemento.AnoPublicacao == (*livrosAnoPub)[i].ano)
        {
            (*livrosAnoPub)[i].qtd ++;
            exist=1;
        }
    }
    if(exist==0)
    {
        (*quantidade)++;
        (*livrosAnoPub) = realloc((*livrosAnoPub),(*quantidade)*sizeof(operacao9counter));
        (*livrosAnoPub)[(*quantidade)].ano = LIVROS->Elemento.AnoPublicacao;
        (*livrosAnoPub)[(*quantidade)].qtd = 1;
    }
    operacao9Aux(LIVROS->Esquerda,livrosAnoPub,quantidade);
    operacao9Aux(LIVROS->Direita,livrosAnoPub,quantidade);
}

void operacao9(PNodoAB LIVROS)
{
    int quantidade=0, anoMax=0,qtdMax=0;
    operacao9counter * livrosAnoPub = malloc(quantidade*sizeof(operacao9counter));
    operacao9Aux(LIVROS,&livrosAnoPub,&quantidade);
    if(quantidade==0)
        printf("Não há publicações.\n");
    else
    {
        for(int i = 0;i <quantidade;i++)
        {
            if(livrosAnoPub[i].qtd > qtdMax)
            {
                anoMax = livrosAnoPub[i].ano;
                qtdMax = livrosAnoPub[i].qtd;
            }
        }
        printf("%d teve %d publicações e foi o ano com mais publicações.\n",anoMax,qtdMax);
    }
}