// Bibliotecas
#include <stdio.h>

// Função para ler um dos números da operação
void lerNumero( int i, double *n ) {
  printf( "Numero %d > ", i );
  scanf( "%lf", n );
}

// Função para ler qual a operação pretendida
void lerOperacao( char *o ) {
  printf( "\nOperacao > " );
  scanf( " %c", o );
  while( *o != '+' && *o != '-' && *o != '*' && *o != '/' ) {
    printf( "  ERRO > Operacao invalida\n\nOperacao > " );
    scanf( " %c", o );
  }
  printf( "\n" );
}

// Função que retorna a adição entre dois números
double adicionar( double n1, double n2 ) {
  return n1 + n2;
}

// Função que retorna a subtração entre dois números
double subtrair( double n1, double n2 ) {
  return n1 - n2;
}

// Função que retorna a multiplicação entre dois números
double multiplicar( double n1, double n2 ) {
  return n1 * n2;
}

// Função que retorna a divisão entre dois números
double dividir( double n1, double n2 ) {
  return n1 / n2;
}

// Função que irá retornar o resultado da operação com base na escolha
double calcular( double n1, char o, double n2 ) {
  switch( o ) {
    case '+':
      return adicionar( n1, n2 );
      break;
    case '-':
      return subtrair( n1, n2 );
      break;
    case '*':
      return multiplicar( n1, n2 );
      break;
    case '/':
      return dividir( n1, n2 );
      break;
  }
}

// Função que imprime o resultado da operação pretendida
void imprimirOperacao( double n1, char o, double n2 ) {
  double r = calcular( n1, o, n2 );
  printf( "\nResultado > %.2lf %c %.2lf = %.2lf\n\n", n1, o, n2, r );
}

// Programa
void main() {
  char op;
  double num1, num2;

  lerNumero( 1, &num1 );
  lerOperacao( &op );
  lerNumero( 2, &num2 );
  imprimirOperacao( num1, op, num2 );
}
