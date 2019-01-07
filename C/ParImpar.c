// Incluir as bibliotecas
#include <stdio.h>

// Ponto para iniciar o programa
void main() {
  int numero;
  do {
    printf( "\n  ------------\n  PAR OU IMPAR\n  ------------\n\n  Numero (0 para sair) > " );
    scanf( "%d", &numero );
    if( numero != 0 ) {
      printf( "  Resultado > " );
      if( numero % 2 ) {
        printf( "IMPAR\n" );
      } else {
        printf( "PAR\n" );
      }
    } else {
      continue;
    }
  } while( numero != 0 );
  printf( "\n  ------------\n\n  Prima [ENTER] para terminar . . . " );
  getch();
}
