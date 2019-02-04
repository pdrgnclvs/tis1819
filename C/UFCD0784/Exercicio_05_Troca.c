// Bibliotecas
#include <stdio.h>

// Função para ler dois números inteiros
void lerNumeros( int *n1, int *n2 ) {
  printf( "Numero 1 > " );
  scanf( "%d", n1 );
  printf( "Numero 2 > " );
  scanf( "%d", n2 );
}

// Função para trocar os valores entre os endereços de memória
void trocarNumeros( int *n1, int *n2 ) {
  int aux = *n1;
  *n1 = *n2;
  *n2 = aux;
}

// Função que devolve os valores nas suas posições
void devolverNumeros( int n1, int n2 ) {
  printf( "\nPosicao 1 > %d\nPosicao 2 > %d", n1, n2 );
}

// Programa
void main() {
  int num1, num2;
  lerNumeros( &num1, &num2 );
  trocarNumeros( &num1, &num2 );
  devolverNumeros( num1, num2 );
}
