// Bibliotecas
#include <stdio.h>
// Constantes
#define MIL_QUI 1.609 // Factor de coversão

// Função para ler a distância em milhas
void lerDistancia( double *milhas ) {
  do {
    printf( "Milhas > " );
    scanf( "%lf", milhas );
  } while( *milhas <= 0 );
}

// Função para converter a distância em quilómetros
double converterDistancia( double distancia ) {
  return MIL_QUI * distancia;
}

// Função para devolver a distância já convertida em quilómetros
void devolverDistancia( double quilometros ) {
  printf( "Quilometros > %4.2f\n\n", quilometros );
}

// Programa
int main( void ) {
  double milhas, quilometros;
  lerDistancia( &milhas );
  quilometros = converterDistancia( milhas );
  devolverDistancia( quilometros );
  return 0;
}
