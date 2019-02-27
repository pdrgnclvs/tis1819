// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define LIMITE 3

// Estrutura
struct livro {
  char titulo[ 50 ];
  char autor[ 50 ];
  char area[ 30 ];
  char isbn[ 20 ];
  int ano;
};

void inserirLivro( struct livro *destino, int *contagem ) {
  printf( "    Titulo: " );
  fflush( stdin );
  fgets( destino -> titulo, 50, stdin );
  printf( "    Autor: " );
  fflush( stdin );
  fgets( destino -> autor, 50, stdin );
  printf( "    Area: " );
  fflush( stdin );
  fgets( destino -> area, 30, stdin );
  printf( "    ISBN: " );
  fflush( stdin );
  fgets( destino -> isbn, 20, stdin );
  printf( "    Ano: " );
  scanf( "%d", &destino -> ano );
  *contagem += 1;
}

void listarLivros( struct livro *fonte, int contagem ) {
  for( int i = 0; i < contagem; i++ ) {
    printf( "\n    Livro #%d\n", i + 1 );
    printf( "      Titulo: %s", fonte[ i ].titulo);
    printf( "      Autor: %s", fonte[ i ].autor);
    printf( "      Area: %s", fonte[ i ].area);
    printf( "      ISBN: %s", fonte[ i ].isbn);
    printf( "      ano: %d", fonte[ i ].ano);
  }
}

void apagarLivro( struct livro *fonte, int *contagem ) {
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

void guardarFicheiro( struct livro *fonte, int contagem ) {
  FILE *ficheiro;
  char *nome = "./bin/biblioteca.txt";

  ficheiro = fopen( nome, "w+" );
  fputs( "BIBLIOTECA MUNICIPAL DE VISEU", ficheiro );
  if( contagem != 0 ) {
    for( int i = 0; i < contagem; i++ ) {
      fputs( "\n\n", ficheiro );
      fputs( "  Livro #", ficheiro );
      fprintf( ficheiro, "%d", i + 1 );
      fputc( '\n', ficheiro );
      fputs( "    Titulo: ", ficheiro );
      fputs( fonte[ i ].titulo, ficheiro );
      fputs( "    Autor: ", ficheiro );
      fputs( fonte[ i ].autor, ficheiro );
      fputs( "    Area: ", ficheiro );
      fputs( fonte[ i ].area, ficheiro );
      fputs( "    ISBN: ", ficheiro );
      fputs( fonte[ i ].isbn, ficheiro );
      fputs( "    Ano: ", ficheiro );
      fprintf( ficheiro, "%d", fonte[ i ].ano );
    }
  } else fputs( "\n\n  Nao existem livros no sistema!", ficheiro );
  fclose( ficheiro );
  printf( "    SUCESSO > Ficheiro gravado!" );
}

void lerFicheiro() {
  FILE *ficheiro;
  char *nome = "./bin/biblioteca.txt";

  if( ( ficheiro = fopen( nome, "rb" ) ) == NULL ) {
    printf( "    ERRO > Ficheiro inexistente" );
  } else {
    ficheiro = fopen( nome, "r" );
    char caracter = fgetc( ficheiro );
    printf( "\n  [ INICIO ]\n\n" );
    while( caracter != EOF ) {
      printf( "%c", caracter );
      caracter = fgetc( ficheiro );
    }
    fclose( ficheiro );
    printf( "\n\n  [ FIM ]" );
  }
}

void main() {
  int opcao, existentes = 0;
  struct livro livros[ LIMITE ] = { 0 };

  do {
    printf( "\n  BIBLIOTECA MUNICIPAL DE VISEU\n\n  1: Sair\n  2: Inserir\n  3: Listar\n  4: Apagar\n\n  5: Guardar\n  6: Ler\n\n  O que pretende fazer? " );
    scanf( "%d", &opcao );

    switch( opcao ) {
      case 2:
        printf( "\n  > INSERIR LIVRO\n");
        if( existentes < LIMITE ) {
          inserirLivro( &livros[ existentes ], &existentes );
        } else printf( "    AVISO: Sistema cheio!" );
        break;
      case 3:
        printf( "\n  > LISTAR LIVROS\n");
        if( existentes != 0 ) {
          listarLivros( livros, existentes );
        } else printf( "    AVISO: Sistema vazio!" );
        break;
      case 4:
        printf( "\n  > APAGAR LIVRO\n");
        if( existentes != 0 ) {
          apagarLivro( livros, &existentes );
        } else printf( "    AVISO: Sistema vazio!" );
        break;
      case 5:
        printf( "\n  > GUARDAR FICHEIRO\n");
        guardarFicheiro( livros, existentes );
        break;
      case 6:
        printf( "\n  > LER FICHEIRO\n");
        lerFicheiro();
        break;
      default:
        break;
    }
    printf( "\n\n- ======= -\n" );
  } while( opcao != 1 );
}
