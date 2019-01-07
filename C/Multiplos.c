// Incluir as bibliotecas
#include <stdio.h>

// Ponto para iniciar o programa
void main() {
  int numA, numB;
  printf( "\n  ---------\n  MULTIPLOS\n  ---------\n\n  A > " );
  scanf( "%d", &numA );
  printf( "  B > " );
  scanf( "%d", &numB );
  printf( "\n  ---------\n" );
  if( numA == numB ) {
    printf( "\n  RESULTADO > Os numeros sao iguais, logo A pode ser dividido por B assim como B pode ser dividido por A!" );
  } else if( numA % numB == 0 ) {
    printf( "\n  RESULTADO > A pode ser dividido por B, sendo que o resultado seria %d!", numA / numB );
  } else if( numB % numA == 0 ) {
    printf( "\n  RESULTADO > B pode ser dividido por A, sendo que o resultado seria %d!", numB / numA );
  } else {
    printf( "\n  ERRO > Nem A nem B podem ser divididos entre si!" );
  }
  printf( "\n\n  ---------\n\n  Prima [ENTER] para terminar . . . " );
  getch();
}
