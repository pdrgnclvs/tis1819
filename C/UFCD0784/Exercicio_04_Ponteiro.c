// Bibliotecas
#include <stdio.h>
#include <malloc.h>

// Função que indica a alocação de memória
void leitura( px )
  int **px;
  {
    *px = (int *)malloc( sizeof( int ) );
    printf( "Valor > " );
    scanf( "%d", *px );
}

// Programa
void main() {
  void leitura();
  int *p;
  leitura( &p );
  printf( "Resultado > %d\n\n", *p );
}
