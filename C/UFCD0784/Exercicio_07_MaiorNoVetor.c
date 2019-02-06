// Bibliotecas
#include <stdio.h>

// Função para ler um número real de forma sequencial
void lerNumero( int i, double *n ) {
  printf( "Numero %d > ", i + 1 );
  scanf( "%lf", n );
}

// Função para devolver a posição do maior número real existente num vetor
int posicaoDoMaior( double v[], int l ) {
  int p = 0;
  for( int i = 0; i < l; i++ ) {
    if( v[ i ] > v[ p ] ) {
      p = i;
    }
  }
  return p;
}

// Função para devolver o maior número real e a sua posição
void devolverMaior( double n, int p ) {
  printf( "\nMaior > %.2lf, armazenado na posicao %d do vetor\n\n", n, p );
}

// Programa
void main() {
  int limite = 3, posicao;
  double vetor[ limite ];

  for( int indice = 0; indice < limite; indice++ ) {
    lerNumero( indice, &vetor[ indice ] );
  }
  posicao = posicaoDoMaior( vetor, limite );
  devolverMaior( vetor[ posicao ], posicao );
}
