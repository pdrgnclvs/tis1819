#include <stdio.h>
#include <stdlib.h>

void main() {
  char _;
  printf( "Caracter: " );
  scanf( "%c", &_ );
  if( _ >= '0' && _ <= '9' ) {
    printf( "Digito" );
  } else if( _ >= 'a' && _ <= 'z' ) {
    printf( "Minuscula" );
  } else if( _ >= 'A' && _ <= 'Z' ) {
    printf( "Maiuscula" );
  } else {
    printf( "Invalido" );
  }
  printf( "\n\n" );
  system( "PAUSE" );
}
