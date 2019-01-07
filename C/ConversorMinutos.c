// Incluir as bibliotecas
#include <stdio.h>

// Ponto para iniciar o programa
void main() {
  char letra;
  int tempo, minutos = 0, horas = 0;
  printf( "\n  -------------------------------\n  CONVERSOR DE MINUTOS PARA HORAS\n  -------------------------------\n\n  Valor (minutos) > " );
  scanf( "%d", &tempo );
  printf( "\n  -------------------------------\n" );

  if( tempo < 0 || tempo > 1440 ) {
    printf( "\n  ERRO > Apenas posso calcular as primeiras 24 horas, ou seja, 1440 minutos!" );
  } else {
    horas = tempo / 60;
    minutos = tempo % 60;
    letra = 'A';
    if( horas > 12 ) {
      horas -= 12;
      letra = 'P';
    }
    printf( "\n  Resultado (horas) > %d:%d %cM", horas, minutos, letra);
  }
  printf( "\n\n  -------------------------------\n\n  Prima [ENTER] para terminar . . . " );
  getch();
}
