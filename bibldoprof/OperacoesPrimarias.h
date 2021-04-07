
typedef struct{
  int   NIF;
  int   Telefone;
  int   NFatura;
  float Pagamento;
}INFO;


void MostrarElemento (INFO X){
  printf("%d - ", X.NIF);
  printf("%d - ", X.Telefone);
  printf("%d - ", X.NFatura);
  printf("%f\n",  X.Pagamento);
}

INFO CriarElemento (){
  INFO X;
  X.NIF = gerarNumeroInteiro(6780, 6790);
  X.Telefone = gerarNumeroInteiro(912345678, 923456789);
  X.NFatura = gerarNumeroInteiro(1000, 2000);
  X.Pagamento = gerarNumeroReal(10.0, 1000.0);
  return X;
}

// comparação de 2 elementos do tipo INFO, segundo o campo NIF
//   devolve -1 se X < Y, 0 se X = Y, 1 se X > Y
int CompararElementos (INFO X, INFO Y){
  if (X.NIF > Y.NIF)
    return 1;
  if (X.NIF < Y.NIF)
    return -1;
  return 0;
}


