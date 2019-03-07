// Bibliotecas
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Função que imprime o título do programa, assim como qualquer outro texto
void cabecalho( char *t ) {
  int x = strlen( t );
  printf( "\n  **" );
  for( int i = 0; i < x; i++ ) {
    printf( "*" );
  }
  printf( "**\n  * %s *\n  **", t );
  for( int i = 0; i < x; i++ ) {
    printf( "*" );
  }
  printf( "**" );
  printf( "\n\n    [C]elsius\n    [F]ahrenheit\n    [K]elvin\n\n", t );
}

// Função para ler uma temperatura sem ter a escala desta em consideração
void lerTemperatura( double *t ) {
  printf( "  Valor > " );
  scanf( "%lf", t );
}

void lerEscalas( char *d, char *p ) {
  printf( "  De > " );
  scanf( " %c", d );
  tolower( *d );
  while( *d != 'c' && *d != 'f' && *d != 'k' ) {
    printf( "    ERRO > Escala desconhecida; tente novamente, por favor\n  De > " );
    scanf( " %c", d );
    tolower( *d );
  }
  ////////////////////////////////////////////////////////////////////////////
  printf( "  Para > " );
  scanf( " %c", p );
  tolower( *p );
  while( ( *p == *d ) || (*p != 'c' && *p != 'f' && *p != 'k') ) {
    printf( "    ERRO > " );
    if( *p == *d ) {
      printf( "Escalas inicial e final iguais" );
    } else {
      printf( "Escala desconhecida" );
    }
    printf( "; tente novamente, por favor\n  Para > " );
    scanf( " %c", p );
    tolower( *p );
  }
}




// Celsius
double celsius( double v, char e ) {
  if( e == 'f' ) {
    v = (v * 1.8) + 32;
  } else if( e == 'k' ) {
    v += 273.15;
  }
  return v;
}

// Fahrenheit
double fahrenheit( double v, char e ) {
  if( e == 'c' ) {
    v = (v - 32) / 1.8 ;
  } else if( e == 'k' ) {
    v = ((v - 32) / 1.8) + 273.15;
  }
  return v;
}

// Kelvin
double kelvin( double v, char e ) {
  if( e == 'c' ) {
    v -= 273.15;
  } else if( e == 'f' ) {
    v = (( v - 273.15 ) * 1.8) + 32;
  }
  return v;
}

double converter( double t, char d, char p ) {
  printf( "%lf > ", t );
  switch( d ) {
    case 'c':
      printf( "Celsius: " );
      printf( "%lf", celsius( t, p ) );
      break;
    case 'f':
      printf( "Fahr: " );
      printf( "%lf", fahrenheit( t, p ) );
      break;
    case 'k':
      printf( "Kelvin: " );
      printf( "%lf", kelvin( t, p ) );
      break;
  }
}


// Programa
void main() {
  char de, para;
  double temperatura;

  cabecalho( "TEMPERATURAS" );
  lerTemperatura( &temperatura );
  lerEscalas( &de, &para );
  converter( temperatura, de, para );
}
