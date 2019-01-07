// Incluir as bibliotecas
#include <stdio.h>

// Definir as constantes
#define ANO_ACTUAL 2019

// Ponto para iniciar o programa
void main() {
  int dia, mes, ano;
  printf( "\n  -------------\n  DATA DESEJADA\n  -------------\n\n  Dia > " );
  scanf( "%d", &dia );
  printf( "  Mes > " );
  scanf( "%d", &mes );
  printf( "  Ano > " );
  scanf( "%d", &ano );
  printf( "\n  -------------\n\n  " );
  if( mes < 1 || mes > 12 || dia < 1 || dia > 31 ) {
    printf( "ERRO > Data nao existe!" );
  } else if( mes == 2 && dia > 28 && ano % 4 != 0 ) {
    printf( "ERRO > Visto que esse ano nao era bissexto, o mes de Fevereiro apenas teve 28 dias!" );
  } else if( dia > 30 && ( mes == 4 ||  mes == 6 || mes == 9 || mes == 11 ) ) {
    printf( "ERRO > Mes introduzido apenas possui 30 dias!" );
  } else if( ano < ANO_ACTUAL ) {
    printf( "SUCESSO > Parabéns! Data correcta e existente!" );
  } else {
    printf( "ERRO > Data futura, e como tal nao conta!" );
  }
  printf( "\n\n  -------------\n\n  Prima [ENTER] para terminar . . . " );
  getch();
}
