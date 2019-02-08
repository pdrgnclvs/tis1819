// Bibliotecas
#include <stdio.h>

// Função para ler um vetor de números reais de um tamanho definido
void lerVetor( char n, double *v, int t ) {
  for( int i = 0; i < t; i++ ) {
    printf( "Coordenada %c%d > ", n, i + 1 );
    scanf( "%lf", &v[i] );
  }
  printf( "\n" );
}

// Função para multiplicar dois números reais entre si
double multiplicarNumeros( double n1, double n2 ) {
  return n1 * n2;
}

// Programa
void main() {
  int limite = 3;
  double vetorA[ limite ], vetorB[ limite ], resultados[ limite ], total;

  lerVetor( 'A', vetorA, limite );
  lerVetor( 'B', vetorB, limite );

  for( int indice = 0; indice < limite; indice++ ) {
    resultados[ indice ] = multiplicarNumeros( vetorA[ indice ], vetorB[ indice ] );
    printf( "\nA%d * B%d > %.2lf * %.2lf = %.2lf", indice + 1, indice + 1, vetorA[ indice ], vetorB[ indice ], resultados[ indice ] );
    total += resultados[ indice ];
  }

  printf( "\n\nTotal > %.2lf\n\n", total );
}
