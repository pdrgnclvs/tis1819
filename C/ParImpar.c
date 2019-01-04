#include <stdio.h>
#include <stdlib.h>

void main() {
  int numero;
  do {
    printf( "Numero: " );
    scanf( "%d", &numero );
    if( numero == 0 ) {
      continue;
    } else {
      printf( "Resultado: " );
      if( numero % 2 ) {
        printf( "IMPAR" );
      } else {
        printf( "PAR" );
      }
    }
  printf( "\n\n" );
  } while( numero != 0 );
  system( "PAUSE" );
}
