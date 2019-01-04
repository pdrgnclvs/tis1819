#include<stdio.h>
#include<stdlib.h>

void main() {
    int tempo, minutos = 0, horas = 0;
    printf( "\n  -------------------------------\n  CONVERSOR DE MINUTOS PARA HORAS\n  -------------------------------\n\n  Valor (minutos) > " );
    scanf( "%d", &tempo );
    if( tempo > 1440 ) {
        printf( "\n  ERRO > Apenas posso calcular as primeiras 24 horas, ou seja, 1440 minutos!" );
    } else {
        minutos = tempo % 60;
        horas = ( tempo - minutos ) / 60;
        printf( "\n  Resultado (horas) > %dh%d", horas, minutos);
    }
    printf( "\n\n  -------------------------------\n\n  " );
    system( "PAUSE" );
}
