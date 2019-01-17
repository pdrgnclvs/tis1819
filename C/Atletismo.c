// Incluir as bibliotecas essenciais
#include <stdio.h>

// Aguardar um [ENTER] para terminar
void quit() {
  printf( "\n\n  Prima [ENTER] para continuar . . . " );
  fflush( stdin );
  getchar();
}

// Ponto de arranque do programa
void main() {
  char sexo, federado, codigoFederado[15], nome[15];
  int idade, lugar;
  printf( "\n  ---------------------\n  MARATONA DE ATLETISMO\n  ---------------------\n\n  Nome > " );
  scanf( "%s", &nome );
  printf( "\n  Idade > " );
  scanf( "%d", &idade );
  if( idade < 16 ) {
    printf( "\n  ---------------------\n  ERRO > Apenas podem participar atletas com 16 ou mais anos!" );
  } else {
    printf( "\n  Sexo (M/F) > " );
    scanf( " %c", &sexo );
    printf( "\n  Federado (S/N) > " );
    scanf( " %c", &federado );
    if( federado == 'S' || federado == 's' ) {
      printf( "    Codigo > " );
      scanf( "%s", &codigoFederado );
    }
    printf( "\n  Lugar > " );
    scanf( "%d", &lugar );
    printf( "\n  ---------------------\n\n  RESULTADO > " );
    switch( sexo ) {
      case 'F':
      case 'f':
        printf( "A atleta %s", nome );
        if( federado == 'S' || federado == 's' ) {
          printf( ", federada com o codigo %s,\n             ", codigoFederado );
        }
        printf( " terminou em %do lugar no escalao ", lugar );
        if( idade >= 16 && idade < 19 ) {
          printf( "Cadetes/Juniores" );
        } else if( idade >= 19 && idade < 29 ) {
          printf( "Sub23/Elite" );
        } else {
          printf( "Master" );
        }
        break;
      case 'M':
      case 'm':
        printf( "O atleta %s", nome );
        if( federado == 'S' || federado == 's' ) {
          printf( ", federado com o codigo %s,\n             ", codigoFederado );
        }
        printf( " terminou em %do lugar no escalao ", lugar );
        if( idade >= 16 && idade < 19 ) {
          printf( "Cadetes/Juniores" );
        } else if( idade >= 19 && idade < 23 ) {
          printf( "Sub23" );
        } else if( idade >= 23 && idade < 30 ) {
          printf( "Elite" );
        } else if( idade >= 30 && idade < 40 ) {
          printf( "Master 30" );
        } else if( idade >= 40 && idade < 50 ) {
          printf( "Master 40" );
        } else if( idade >= 50 && idade < 60 ) {
          printf( "Master 50" );
        } else {
          printf( "Master 60" );
        }
      break;
    }
    switch( lugar ) {
      case 1:
        printf( ",\n              conquistando uma MEDALHA DE OURO!" );
        break;
      case 2:
        printf( ",\n              conquistando uma MEDALHA DE PRATA!" );
        break;
      case 3:
        printf( ",\n              conquistando uma MEDALHA DE BRONZE!" );
        break;
      default:
        printf( ",\n              nao conquistando nenhuma medalha!" );
        break;
    }
  }
  printf( "\n\n  ---------------------" );
  quit();
}
