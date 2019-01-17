// Incluir as bibliotecas essenciais
#include <stdio.h>

// Aguardar um [ENTER] para terminar
void quit() {
  printf( "\n\n  Prima [ENTER] para continuar . . . " );
  fflush( stdin );
  getchar();
}

// Ponto de arranque do programa
void main() {
  char caracter;
  printf( "\n  --------\n  CARACTER\n  --------\n\n  Caracter > " );
  scanf( "%c", &caracter );
  printf( "\n  --------\n\n  RESPOSTA > " );
  if( caracter >= '0' && caracter <= '9' ) {
    printf( "Digito" );
  } else if( caracter >= 'a' && caracter <= 'z' ) {
    printf( "Minuscula" );
  } else if( caracter >= 'A' && caracter <= 'Z' ) {
    printf( "Maiuscula" );
  } else {
    printf( "Invalido" );
  }
  printf( "\n\n  --------\n\n  Prima [ENTER] para terminar . . . " );
  getch();
}
