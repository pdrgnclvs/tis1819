// Bibliotecas
#include <stdio.h>

// Função para ler um número inteiro
void lerNumero( int *n ) {
  printf( "Conteudo > " );
  scanf( "%d", n );
}

// Função para devolver um número inteiro e a posição do mesmo num vetor
void devolverNumero( int i, int n ) {
  printf( "Vetor[%d] > %d\n\n", i, n );
}

// Programa
void main() {
  int numeros[ 9 ];

  for( int i = 0; i < 10; i++ ) {
    lerNumero( &numeros[ i ] );
    devolverNumero( i, numeros[ i ] );
  }
}
