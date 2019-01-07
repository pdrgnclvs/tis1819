// Incluir as bibliotecas
#include <stdio.h>

// Ponto para iniciar o programa
void main() {
  int maior, numeroUm, numeroDois, numeroTres;
  printf( "\n  ------------\n  NUMERO MAIOR\n  ------------\n\n  Introduza os 3 valores que pretende comparar...\n\n  > " );
  scanf( "%d", &numeroUm );
  printf( "  > " );
  scanf( "%d", &numeroDois );
  printf( "  > " );
  scanf( "%d", &numeroTres );
  maior = numeroUm;
  if( numeroDois > maior ) {
    maior = numeroDois;
  }
  if( numeroTres > maior ) {
    maior = numeroTres;
  }
  printf( "\n  ------------\n\n  MAIOR > %d", maior );
  if( numeroUm == numeroDois || numeroDois == numeroTres || numeroTres == numeroUm ) {
    printf( " > No entanto, foram introduzidos VALORES REPETIDOS no programa!" );
  }
  printf( "\n\n  ------------\n\n  Prima [ENTER] para terminar . . . " );
  getch();
}
