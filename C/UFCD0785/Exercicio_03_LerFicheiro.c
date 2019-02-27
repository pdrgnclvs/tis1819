// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa
void main() {
  FILE *fp;
  char *nome = "./bin/exercicio.txt";
  char st[ 50 ], c;

  fp = fopen( nome, "r" );
  c = fgetc( fp );
  while( c != EOF ) {
    printf( "%c", c );
    c = fgetc( fp );
  }
  fclose( fp );
}
