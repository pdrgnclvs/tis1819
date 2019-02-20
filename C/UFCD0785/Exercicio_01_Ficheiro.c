// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa
void main() {
  FILE *fp;
  char *nome = "./bin/exercicio.txt";
  char st[ 50 ];

  fp = fopen( nome, "w+" );
  printf( "\n  BLOCO DE NOTAS (DOS POBRES)\n\n  Introduza strings, premindo [ENTER] no final; o 0 termina!\n\n" );
  do {
    printf( "  > " );
    gets( st );
    if( strcmp( "0", st ) ) {
      fputs( st, fp );
      putc( '\n', fp );
    }
  } while( strcmp( "0", st ) );
  fclose( fp );
}
