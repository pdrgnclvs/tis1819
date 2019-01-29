#include <stdio.h>
#define MIL_QUI 1.609 // Factor de coversão

int main( void ) {
  double milhas, quilometros;
  do {
    printf( "Milhas? " );
    scanf( "%lf", &milhas );
  } while( milhas <= 0 );
  quilometros = MIL_QUI * milhas;
  printf( "Corresponde a %4.2f quilometros!\n", quilometros );
  return 0;
}
