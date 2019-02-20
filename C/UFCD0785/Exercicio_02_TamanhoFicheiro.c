// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa
void main() {
  FILE *fp;
  char *nome = "./bin/exercicio.txt";
  long int tamanho;

  if( ( fp = fopen( nome, "rb" ) ) == NULL ) {
    printf( "  ERRO > Ficheiro inexistente" );
  } else fseek( fp, 0L, SEEK_END );

  printf( "  Tamanho: %d", ftell( fp ) );
  fclose( fp );
}
