#include <stdio.h>
#include <stdlib.h>

void main() {
    int maior, numeroUm, numeroDois, numeroTres;
    printf( "\n  Introduza os 3 valores que pretende comparar...\n\n" );
    scanf( "%d", &numeroUm );
    scanf( "%d", &numeroDois );
    scanf( "%d", &numeroTres );

    maior = numeroUm;
    if( numeroDois > maior ) {
        maior = numeroDois;
    }
    if( numeroTres > maior ) {
        maior = numeroTres;
    }
    printf( "\n  Maior: %d", maior );
    if( numeroUm == numeroDois || numeroDois == numeroTres || numeroTres == numeroUm ) {
        printf( " [REPETIDO]" );
    }
    printf( "\n\n  " );
    system( "PAUSE" );
}
