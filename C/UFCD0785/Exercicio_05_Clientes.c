// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Constantes
#define LIMITE 3

// Estrutura
struct cliente {
  char nome[ 50 ];
  char morada[ 20 ];
  int telefone;
  int idade;
  char sexo;
};

void inserirCliente( struct cliente *destino, int *contagem ) {
  printf( "    Nome: " );
  fflush( stdin );
  fgets( destino -> nome, 50, stdin );
  printf( "    Morada: " );
  fflush( stdin );
  fgets( destino -> morada, 20, stdin );
  printf( "    Telefone: " );
  scanf( "%d", &destino -> telefone );
  printf( "    Idade: " );
  scanf( "%d", &destino -> idade );
  printf( "    Sexo: " );
  scanf( " %c", &destino -> sexo );
  destino -> sexo = toupper( destino -> sexo );
  *contagem += 1;
}

void listarClientes( struct cliente *fonte ) {
  for( int i = 0; i < LIMITE; i++ ) {
    if( strlen( fonte[ i ].nome ) != 0 ) {
      printf( "\n    Cliente #%d\n", i + 1 );
      printf( "      Nome: %s", fonte[i].nome);
      printf( "      Morada: %s", fonte[i].morada);
      printf( "      Telefone: %d\n", fonte[i].telefone);
      printf( "      Idade: %d\n",fonte[i].idade);
      printf( "      Sexo: %c",fonte[i].sexo);
    }
  }
}

void apagarCliente( struct cliente *fonte, int *contagem ) {
  int posicao;
  printf( "    Posto [1-%d]: ", *contagem );
  scanf( "%d", &posicao );
  if( ( posicao < 1 ) || ( posicao > *contagem ) ) {
    printf( "      ERRO: Posto incorrecto!\n");
    return;
  }

  if( posicao == *contagem ) {
    *contagem -= 1;
    return;
  }

  for( int i = posicao - 1; i < LIMITE; i++ ) {
    fonte[ i ] = fonte[ i + 1 ];
  }
  *contagem -= 1;
}










void main() {
  int opcao, existentes = 0;
  struct cliente clientes[ LIMITE ] = { 0 };



do {
  printf( "\n  LOJINHA\n\n  1: Sair\n  2: Inserir\n  3: Listar\n  4: Apagar\n\n  O que pretende fazer? " );
  scanf( "%d", &opcao );

  switch( opcao ) {
    case 2:
      printf( "\n  > INSERIR CLIENTE\n");
      if( existentes < LIMITE ) {
        inserirCliente( &clientes[ existentes ], &existentes );
      } else printf( "    AVISO: Sistema cheio!" );
      break;
    case 3:
      printf( "\n  > LISTAR CLIENTES\n");
      if( existentes != 0 ) {
        listarClientes( clientes );
      } else printf( "    AVISO: Sistema vazio!" );
      break;
    case 4:
      printf( "\n  > APAGAR CLIENTE\n");
      if( existentes != 0 ) {
        apagarCliente( clientes, &existentes );
      } else printf( "    AVISO: Sistema vazio!" );
      break;
    default:
      break;
  }


  printf( "\n\n- ======= -\n" );


  } while( opcao != 1 );


















}
