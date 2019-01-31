// Bibliotecas
#include <stdio.h>
// Constantes
#define MIL_QUI 1.609 // Factor de coversão

// Programa
int main( void ) {
  double milhas, quilometros;
  do {
    printf( "Milhas > " );
    scanf( "%lf", &milhas );
  } while( milhas <= 0 );
  quilometros = MIL_QUI * milhas;
  printf( "Quilometros > %4.2f\n\n", quilometros );
  return 0;
}
