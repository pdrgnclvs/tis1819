// Incluir as bibliotecas
#include <stdio.h>

// Ponto para iniciar o programa
void main() {
  char cargo;
  float salarioActual, novoSalario, aumento;
  printf( "\n  ----------------\n  AUMENTO SALARIAL\n  ----------------\n\n  Salario > " );
  scanf( "%f", &salarioActual );
  printf( "\n  ---- CARGOS ----\n  G > Gerente\n  E > Engenheiro\n  T > Tecnico\n  ? > Outros\n  ----------------\n\n  Cargo > " );
  scanf( "%s", &cargo );
  printf( "\n  ----------------\n" );
  if( cargo == 'g' || cargo == 'G' ) {
    aumento = 0.1;
  } else if( cargo == 'e' || cargo == 'E' ) {
    aumento = 0.2;
  } else if( cargo == 't' || cargo == 'T' ) {
    aumento = 0.3;
  } else {
    aumento = 0.4;
  }
  novoSalario = salarioActual + ( salarioActual * aumento );
  printf( "\n  Salario Actual > %.2f\n  Novo Salario   > %.2f\n  Aumento de %.0f%% > %.2f", salarioActual, novoSalario, aumento * 100, novoSalario - salarioActual );
  printf( "\n\n  ----------------\n\n  Prima [ENTER] para terminar . . . " );
  getch();
}
