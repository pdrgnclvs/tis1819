#include <stdio.h>
#define MIL_QUI 1.609 // Factor de coversão

void lerDistancia( double *milhas ) {
  do {
    printf( "Milhas? " );
    scanf( "%lf", milhas );
  } while( *milhas <= 0 );
}
double converterDistancia( double distancia ) {
  return MIL_QUI * distancia;
}
void devolverDistancia( double quilometros ) {
  printf( "Corresponde a %4.2f quilometros!\n", quilometros );
}

int main( void ) {
  double milhas, quilometros;
  lerDistancia( &milhas );
  quilometros = converterDistancia( milhas );
  devolverDistancia( quilometros );
  return 0;
}
