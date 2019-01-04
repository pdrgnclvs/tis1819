#include <stdio.h>
#include <stdlib.h>

void main() {
  int tempo, minutos = 0, horas = 0;
  char letra;
  printf( "\n  -------------------------------\n  CONVERSOR DE MINUTOS PARA HORAS\n  -------------------------------\n\n  Valor (minutos) > " );
  scanf( "%d", &tempo );
  if( tempo < 0 || tempo > 1440 ) {
    printf( "\n  ERRO > Apenas posso calcular as primeiras 24 horas, ou seja, 1440 minutos!" );
  } else {
    horas = tempo / 60;
    minutos = tempo % 60;
    letra = 'A';
    if( horas > 12 ) {
      horas -= 12;
      letra = 'M';
    }
    printf( "\n  Resultado (horas) > %d:%d %cM", horas, minutos, letra);
  }
  printf( "\n\n  -------------------------------\n\n  " );
  system( "PAUSE" );
}
