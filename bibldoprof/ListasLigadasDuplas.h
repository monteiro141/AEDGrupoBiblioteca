
struct Nodo {
	INFO  Elemento;
	struct Nodo *Prox;
	struct Nodo *Ant;
};

typedef struct Nodo *PNodo;


void Criar (PNodo *Head, PNodo *Tail){
	*Head = NULL;
	*Tail = NULL;
}

PNodo CriarNodo (INFO X){
	PNodo P;
	P = (PNodo) malloc(sizeof(struct Nodo));
	if (P == NULL)
		return NULL;
	P->Elemento = X;
	P->Prox = NULL;
	P->Ant = NULL;
	return P;
}

PNodo LibertarNodo (PNodo P){ 
  free(P);
	P = NULL;
	return P;
}

int Vazia (PNodo Head){
	if (Head == NULL)
	  return 1;
	else
	  return 0;
}


void Listar (PNodo Head){
	PNodo P = Head;
	while (P != NULL){
		MostrarElemento(P->Elemento);
		P = P->Prox;
	}
	printf("\n\n");
}

void ListarContrario (PNodo Tail){
	PNodo P = Tail;
	while (P != NULL){
		MostrarElemento(P->Elemento);
		P = P->Ant;
	}
	printf("\n\n");
}

int Tamanho (PNodo Head){
	PNodo P = Head;
  int  tam = 0; 
	while (P != NULL){
	  tam++;
		P = P->Prox;
	} 
	return tam;
}

// consultar/pesquisar elemento a partir da cabeça
int ConsultarCabeca (PNodo Head, INFO X){
	PNodo P = Head;
	if (Head == NULL)
	  return 0;
  while (CompararElementos(P->Elemento, X) != 0 && P->Prox != NULL)
	  P = P->Prox; 
	if (CompararElementos(P->Elemento, X) == 0)
	  return 1; 
	return 0;
} 

// consultar/pesquisar elemento a partir da cauda
int ConsultarCauda (PNodo Tail, INFO X){
	PNodo P = Tail;
	if (Tail == NULL)
	  return 0;
  while (CompararElementos(P->Elemento, X) != 0 && P->Ant != NULL)
	  P = P->Ant; 
	if (CompararElementos(P->Elemento, X) == 0)
	  return 1; 
	return 0;
}

// procurar o nodo com um elemento X a partir da cabeça (existe nodo com X)
PNodo Procurar (PNodo Head, INFO X){
	PNodo P = Head;
  while (CompararElementos(P->Elemento, X) != 0)
	  P = P->Prox; 
	return P;
}

void InserirPrimeiroElemento (PNodo *Head, PNodo *Tail, INFO X){
	PNodo P;
	P = CriarNodo(X);
	if (P != NULL){
		*Head = P;
		*Tail = P;
	}
}

PNodo InserirCabeca (PNodo Head, INFO X){
	PNodo P;
	P = CriarNodo(X);
	if (P == NULL)
		return Head;
	P->Prox = Head;
	Head->Ant = P;
	Head = P;
	return Head;
}

PNodo InserirCauda (PNodo Tail, INFO X){
	PNodo P;
	P = CriarNodo(X);
	if (P == NULL)
		return Tail;
	Tail->Prox = P;
	P->Ant = Tail;
	Tail = P;
	return Tail;
}

// operação a usar na operação Inserir
//   procurar o nodo que ficará antes do nodo com o elemento X
//   devolve NULL se X vai ficar na cabeça da lista
PNodo ProcurarOrdem (PNodo Head, INFO X){
	PNodo P, PAnt;
	P = Head;
	PAnt = NULL;
  while (CompararElementos(P->Elemento, X) <= 0 && P->Prox != NULL){
  	PAnt = P;
  	P = P->Prox;
	}
	if (CompararElementos(P->Elemento, X) <= 0)   
		return P;
	return PAnt;
}

PNodo InserirMeio (PNodo Head, INFO X){
	PNodo P, PAnt;
	//PNodo PProx;
	PAnt = ProcurarOrdem(Head, X);
	P = CriarNodo(X);
	if (P == NULL)
		return Head;
	//PProx = PAnt->Prox;
	P->Prox = PAnt->Prox;
	P->Ant = PAnt;
	PAnt->Prox->Ant = P;
	PAnt->Prox = P;
	return Head;
}

void RemoverUnicoElemento (PNodo *Head, PNodo *Tail){ 
  PNodo P = *Head;
  *Head = NULL;
  *Tail = NULL;
	P = LibertarNodo(P); 
}

PNodo RemoverCabeca (PNodo Head){ 
  PNodo P = Head;
  Head->Prox->Ant = NULL;
  Head = Head->Prox;
	P = LibertarNodo(P); 
	return Head;
}

PNodo RemoverCauda (PNodo Tail){ 
  PNodo P = Tail;
  Tail->Ant->Prox = NULL;
  Tail = Tail->Ant;
	P = LibertarNodo(P); 
	return Tail;
}

PNodo RemoverMeio (PNodo Head, INFO X){ 
  PNodo P;
  P = Procurar(Head, X);
  P->Ant->Prox = P->Prox;
  P->Prox->Ant = P->Ant;
	P = LibertarNodo(P); 
	return Head;
}
