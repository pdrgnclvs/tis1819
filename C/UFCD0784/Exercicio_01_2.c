#include <stdio.h>
#define MIL_QUI 1.609 // Factor de coversão

double converterDistancia( double milhas ) {
  return MIL_QUI * milhas;
}

int main( void ) {
  double milhas;
  do {
    printf( "Milhas? " );
    scanf( "%lf", &milhas );
  } while( milhas <= 0 );
  printf( "Corresponde a %4.2f quilometros!\n", converterDistancia( milhas ) );
  return 0;
}
