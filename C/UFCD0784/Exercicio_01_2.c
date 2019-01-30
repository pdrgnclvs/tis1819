// Bibliotecas
#include <stdio.h>
// Constantes
#define MIL_QUI 1.609 // Factor de coversão

// Função para converter a distância em quilómetros
double converterDistancia( double milhas ) {
  return MIL_QUI * milhas;
}

// Programa
int main( void ) {
  double milhas;
  do {
    printf( "Milhas > " );
    scanf( "%lf", &milhas );
  } while( milhas <= 0 );
  printf( "Quilometros > %4.2f\n\n", converterDistancia( milhas ) );
  return 0;
}
