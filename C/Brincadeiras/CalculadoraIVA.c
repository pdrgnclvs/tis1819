// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definição dos valores normal, intermédio, e reduzido do IVA nas três regiões
#define TAXA_NORMAL_CONTINENTE 23
#define TAXA_NORMAL_MADEIRA 22
#define TAXA_NORMAL_ACORES 18
#define TAXA_INTERMEDIA_CONTINENTE 13
#define TAXA_INTERMEDIA_MADEIRA 12
#define TAXA_INTERMEDIA_ACORES 9
#define TAXA_REDUZIDA_CONTINENTE 6
#define TAXA_REDUZIDA_MADEIRA 5
#define TAXA_REDUZIDA_ACORES 4

// Função que imprime o título do programa, assim como qualquer outro texto
void cabecalho( char *_titulo ) {
  int x = strlen( _titulo );
  printf( "\n  **" );
  for( int i = 0; i < x; i++ ) {
    printf( "*" );
  }
  printf( "**\n  * %s *\n  **", _titulo );
  for( int i = 0; i < x; i++ ) {
    printf( "*" );
  }
  printf( "**" );
  printf( "\n\n" );
}

// Função que permite ao utilizador escolher a região em que se encontra
void escolherZona( char *_zona ) {
  printf( "  Pretende saber o valor com base nas taxas do [C]ontinente, da [M]adeira, ou dos [A]cores? " );
  scanf( " %c", _zona );
  tolower( *_zona );
  while( *_zona != 'c' && *_zona != 'm' && *_zona != 'a' ) {
    printf( "    Repito, taxas do [C]ontinente, da [M]adeira, ou dos [A]cores? " );
    scanf( " %c", _zona );
    tolower( *_zona );
  }
  printf( "\n" );
}

// REPARAR
void escolherNivel( char *_nivel ) {
  printf( "  Pretende calcular com base na taxa [n]ormal, [i]ntermedia, ou [r]eduzida? " );
  scanf( " %c", _nivel );
  tolower( *_nivel );
  while( *_nivel != 'n' && *_nivel != 'i' && *_nivel != 'r' ) {
    printf( "    Repito, com base na taxa [n]ormal, [i]ntermedia, ou [r]eduzida? " );
    scanf( " %c", _nivel );
    tolower( *_nivel );
  }
  printf( "\n" );
}
// REPARAR

void escolherComOuSem( char *_tipo ) {
  printf( "  Pretende saber o valor [c]om ou [s]em IVA? " );
  scanf( " %c", _tipo );
  tolower( *_tipo );
  while( *_tipo != 'c' && *_tipo != 's' ) {
    printf( "    Repito, valor [c]om ou [s]em IVA? " );
    scanf( " %c", _tipo );
    tolower( *_tipo );
  }
  printf( "\n" );
}

void obterValor( double *_valor ) {
  printf( "  Valor? " );
  scanf( "%lf", _valor );
  while( *_valor < 0 ) {
    printf( "    Repito, valor? " );
    scanf( "%lf", _valor );
  }
  printf( "\n" );
}

int devolverTaxa( char _zona, char _nivel ) {
  switch( _zona ) {
    case 'c':
      if( _nivel == 'r' ) {
        return TAXA_REDUZIDA_CONTINENTE;
      } else if( _nivel == 'i' ) {
        return TAXA_INTERMEDIA_CONTINENTE;
      } else {
        return TAXA_NORMAL_CONTINENTE;
      }
      break;
    case 'm':
      if( _nivel == 'r' ) {
        return TAXA_REDUZIDA_MADEIRA;
      } else if( _nivel == 'i' ) {
        return TAXA_INTERMEDIA_MADEIRA;
      } else {
        return TAXA_NORMAL_MADEIRA;
      }
      break;
    case 'a':
      if( _nivel == 'r' ) {
        return TAXA_REDUZIDA_ACORES;
      } else if( _nivel == 'i' ) {
        return TAXA_INTERMEDIA_ACORES;
      } else {
        return TAXA_NORMAL_ACORES;
      }
      break;
  }
}






float calcularTaxa( float _taxa ) {
  return ( _taxa / 100 ) + 1;
}
double comIVA( char _zona, char _nivel, double _preco ) {
  return _preco *= calcularTaxa( devolverTaxa( _zona, _nivel ) );
}
double semIVA( char _zona, char _nivel, double _preco ) {
  return _preco /= calcularTaxa( devolverTaxa( _zona, _nivel ) );
}

void main() {

  char zona, nivel, tipo;
  double preco;

  cabecalho( "CALCULAR IVA" );

  escolherZona( &zona );
  escolherNivel( &nivel );
  escolherComOuSem( &tipo );
  obterValor( &preco );

  if( tipo == 'c' ) {
    preco = comIVA( zona, nivel, preco );
  } else if( tipo == 's' ) {
    preco = semIVA( zona, nivel, preco );
  }

  printf( "\n  Taxa: %d", devolverTaxa( zona, nivel ) );
  printf( "\n  Final: %.2lf", preco );
  printf( "\n\n  " );

  system( "PAUSE" );
}
