// Bibliotecas
#include <stdio.h>

// Função para ler um vetor de números inteiros de um tamanho definido
void lerVetor( char n, int *v, int t ) {
  for( int i = 0; i < t; i++ ) {
    printf( "Coordenada %c%d > ", n, i );
    scanf( "%d", &v[i] );
  }
  printf( "\n" );
}

// Programa
void main() {
  int limite = 3;
  int vetorA[ limite ], vetorB[ limite ], final[ limite * 2 ];

  lerVetor( 'A', vetorA, limite );
  lerVetor( 'B', vetorB, limite );

  for( int indice = 0, normal = 0, inverso = limite - 1; indice < ( limite * 2 ); ) {
    final[ indice ] = vetorA[ normal ];
    indice++;
    final[ indice ] = vetorB[ inverso ];
    indice++;
    normal++;
    inverso--;
  }

  for( int indice = 0; indice < ( limite * 2 ); indice++ ) {
    printf( "%d ", final[ indice ] );
  }
}
