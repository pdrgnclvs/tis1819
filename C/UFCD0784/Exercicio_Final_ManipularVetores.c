// Biblioteca
#include <stdio.h>
#include <stdlib.h>

// Função para alocar o tamanho de um vetor
int *aloca( int n ) {
  int *p;
  if( ( p = ( int * ) malloc( n*sizeof( int ) ) ) == NULL ) {
    printf( "Memória insuficiente\n" );
    return NULL;
  } else {
    return p;
  }
}

// Função para definir o tamanho de um vetor
void definirTamanhoDoVetor( int *t ) {
  printf( "Tamanho do vetor > " );
  scanf( "%d", t );
  printf( "\n" );
}

// Função para ler um vetor de números inteiros de um tamanho definido
void lerVetor( int *v, int t ) {
  for( int i = 0; i < t; i++ ) {
    printf( "Coordenada %d > ", i );
    scanf( "%d", &v[i] );
  }
  printf( "\n" );
}

// Função para inverter um vetor de um tamanho definido para um novo vetor
void inverterVetor( int *v, int t, int *d ) {
  for( int ind = 0, inv = t - 1; ind < t; ) {
    d[ inv ] = v[ ind ];
    ind++;
    inv--;
  }
}

// Função para imprimir um vetor de um tamanho definido para um novo vetor
void imprimirVetor( char *s, int *v, int t ) {
  printf( "%s ", s );
  for( int i = 0; i < t; i++ ) {
    printf( " %d ", v[ i ] );
  }
  printf( "\n" );
}

// Função para devolver o maior número de um vetor de um determinado tamanho
int maiorNoVetor( int *v, int t ) {
  int p = 0;
  for( int i = 0; i < t; i++ ) {
    if( v[ i ] > v[ p ] ) {
      p = i;
    }
  }
  return v[ p ];
}

// Função para devolver o menor número de um vetor de um determinado tamanho
int menorNoVetor( int *v, int t ) {
  int p = 0;
  for( int i = 0; i < t; i++ ) {
    if( v[ i ] < v[ p ] ) {
      p = i;
    }
  }
  return v[ p ];
}

// Função para devolver a média de valores de um vetor de um determinado tamanho
double mediaDoVetor( int *v, int t ) {
  double r = 0;
  for( int i = 0; i < t; i++ ) {
    r += v[ i ];
  }
  r /= t;
  return r;
}

// Função para devolver quantos valores estão acima da média de um vetor
int acimaDaMedia( int *v, int t ) {
  double m = mediaDoVetor( v, t );
  int r;
  for( int i = 0; i < t; i++ ) {
    if( v[ i ] > m ) {
      r++;
    }
  }
  return r;
}

// Função para devolver quantos valores estão abaixo da média de um vetor
int abaixoDaMedia( int *v, int t ) {
  double m = mediaDoVetor( v, t );
  int r;
  for( int i = 0; i < t; i++ ) {
    if( v[ i ] < m ) {
      r++;
    }
  }
  return r;
}

// Função para duplicar um vetor de um determinado tamanho
void duplicarVetor( int *f, int t, int *d ) {
  for( int i = 0; i < t; i++ ) {
    d[ i ] = f[ i ];
  }
}

// Programa
void main() {
  int tamanho, *vetor, *inverso, *duplicado;

  definirTamanhoDoVetor( &tamanho );
  vetor = aloca( tamanho );
  inverso = aloca( tamanho );
  duplicado = aloca( tamanho );
  lerVetor( vetor, tamanho );
  inverterVetor( vetor, tamanho, inverso );
  duplicarVetor( vetor, tamanho, duplicado );
  imprimirVetor( "Vetor >", vetor, tamanho );
  imprimirVetor( "Inverso >", inverso, tamanho );
  printf( "\nMaximo > %d", maiorNoVetor( vetor, tamanho ) );
  printf( "\nMinimo > %d", menorNoVetor( vetor, tamanho ) );
  printf( "\nMedia > %.2f", mediaDoVetor( vetor, tamanho ) );
  printf( "\n      > Acima > %d", acimaDaMedia( vetor, tamanho ) );
  printf( "\n      > Abaixo > %d", abaixoDaMedia( vetor, tamanho ) );
  imprimirVetor( "\n\nDuplicado >", duplicado, tamanho );
}
