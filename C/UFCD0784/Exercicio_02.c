// Bibliotecas
#include <stdio.h>

// Função para ler um valor inteiro acima de zero
void ler( int *val ) {
  do {
    printf( "Valor > " );
    scanf( "%d", val );
  } while( *val <= 0 );
}

// Função para calcular o quadrado do valor introduzido
int quadrado( int num ) {
  return num * num;
}

// Função para devolver o valor já calculado
void devolver( int val ) {
  printf( "Quadrado > %d\n", val );
}

// Programa
void main() {
  int numero;
  ler( &numero );
  devolver( quadrado( numero ) );
}
