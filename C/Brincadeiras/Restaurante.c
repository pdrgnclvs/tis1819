// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Preços
#define MENU_CARNE 5.9
#define MENU_PEIXE 6.1
#define MENU_VEGETARIANO 7.5
#define MENU_INFANTIL 3.75
#define BIFES_FRANGO_PANADOS 4.75
#define CARNE_VACA_ESTUFADA 5.25
#define BACALHAU_ASSADO 4.5
#define BIFE_GRELHADO 6.5
#define SALMAO_GRELHADO 6.3
#define OVO_ESTRELADO 1.75
#define ACOMP_ARROZ_BRANCO 2.75
#define ACOMP_BATATA_ASSADA 3.1
#define ACOMP_BATATA_FRITA 1.75
#define ACOMP_MIGAS 2.5
#define BEB_GARRAFA_AGUA 1.75
#define BEB_GARRAFA_VINHO 8.5
#define BEB_REFRIGERANTE 1.2
#define SOBR_DOCE_CASA 2.75
#define SOBR_MOUSSE_CHOCOLATE 1.75
#define SOBR_FRUTA_FRESCA 1.2
#define SOBR_BABA_CAMELO 3.15
#define SOBR_SALADA_FRUTA 1.75
#define CAFE 0.75

// Estrutura que vai armazenar os dados de cada pedido
struct pedido {
  char tipo;
  char menu;
  char prato;
  char acompanhamento;
  char bebida;
  char sobremesa;
  char cafe;
  char fatura;
  char contribuinte[ 10 ];
  double total;
};

// Função para obter um caracter minúsculo para simplificar comparações
char caracter( char *caracter ) {
  return tolower( scanf( " %c", caracter ) );
}

// Função que imprime um cabeçalho no topo do programa
void cabecalho() {
  printf( "\n  ==========================================\n  ====  O GATUNO  -  RESTAURANTE E BAR  ====\n  ==========================================\n" );
}

// Função que aguarda por um [ENTER] antes do programa terminar
void sair() {
  printf( "\n\n  Prima [ENTER] para continuar . . . " );
  fflush( stdin );
  getchar();
}

// Função que mostra uma breve apresentação
void apresentacao() {
  printf( "\n  Bem-vindo ao nosso restaurante!\n  Eu sou o Pedro, e irei tratar do(s) seu(s) pedido(s)!\n" );
}

// Função que permite ao utilizador escolher entre menu ou carta
void escolherMenuOuCarta( char *escolha ) {
  printf( "\n  Pretende escolher um [m]enu, ou escolher a partir da [c]arta? " );
  caracter( escolha );
  while( *escolha != 'm' && *escolha != 'c' ) {
    printf( "    Diga? " );
    caracter( escolha );
  }
}

// Função que permite ao utilizador escolher entre um dos menus existentes
void escolherMenu( char *menu, double *conta ) {
  double preco = 0;
  printf( "  Vamos para um menu, excelente escolha!\n\n  Prefere o menu de [c]arne, [p]eixe, [v]egan, ou [i]nfantil? " );
  caracter( menu );
  while( *menu != 'c' && *menu != 'p' && *menu != 'v' && *menu != 'i' ) {
    printf( "    Diga? " );
    caracter( menu );
  }
  switch( *menu ) {
    case 'c': preco = MENU_CARNE; break;
    case 'p': preco = MENU_PEIXE; break;
    case 'v': preco = MENU_VEGETARIANO; break;
    case 'i': preco = MENU_INFANTIL; break;
  }
  *conta += preco;
}

// Função que permite ao utilizador escolher entre um dos pratos existentes
void escolherPrato( char *prato, double *conta ) {
  double preco = 0;
  printf( "  Com certeza, para hoje temos:" );
  // Imprimir pratos aqui
  caracter( prato );
  while( *prato != 'f' && *prato != 'c' && *prato != 'b' && *prato != 'g' && *prato != 's' && *prato != 'o' ) {
    printf( "    Diga? " );
    caracter( prato );
  }
  switch( *prato ) {
    case 'f': preco = BIFES_FRANGO_PANADOS; break;
    case 'c': preco = CARNE_VACA_ESTUFADA; break;
    case 'b': preco = BACALHAU_ASSADO; break;
    case 'g': preco = BIFE_GRELHADO; break;
    case 's': preco = SALMAO_GRELHADO; break;
    case 'o': preco = OVO_ESTRELADO; break;
  }
  *conta += preco;
}

// Função que permite ao utilizador escolher entre um dos acompanhamentos existentes
void escolherAcompanhamento( char *acompanhamento, double *conta ) {
  double preco = 0;
  printf( "Acompanhamento, [s]im? " );
  caracter( acompanhamento );
  if( *acompanhamento != 's' ) {
    *acompanhamento = '_';
  } else {
    printf( "    Temos ainda alguns acompanhamentos!\n\n      [A]rroz branco\n      [B]atata assada\n      Batata [f]rita\n      [M]igas\n      [N]enhum\n\n    Qual pretende? " );
    caracter( acompanhamento );
    while( *acompanhamento != 'a' && *acompanhamento != 'b' && *acompanhamento != 'f' && *acompanhamento != 'm' && *acompanhamento != 'n' ) {
      printf( "      Desculpe? " );
      caracter( acompanhamento );
    }
    switch( *acompanhamento ) {
      case 'a': preco = ACOMP_ARROZ_BRANCO; break;
      case 'b': preco = ACOMP_BATATA_ASSADA; break;
      case 'f': preco = ACOMP_BATATA_FRITA; break;
      case 'm': preco = ACOMP_MIGAS; break;
    }
      *conta += preco;
  }
}

// Função que permite ao utilizador escolher entre uma das bebidas disponíveis
void escolherBebida( char *bebida, double *conta ) {
  double preco = 0;
  printf( "\n  Bebida, [s]im? " );
  caracter( bebida );
  if( *bebida != 's' ) {
    *bebida = '_';
  } else {
    printf( "    Temos...\n\n      [A]gua\n      [V]inho\n      [I]ced Tea\n      [C]oca-Cola\n\n    Qual pretende? " );
    caracter( bebida );
    while( *bebida != 'a' && *bebida != 'v' && *bebida != 'i' && *bebida != 'c' ) {
      printf( "      Diga? " );
      caracter( bebida );
    }
    if( *bebida == 'c' ) {
      printf( "    Pode ser [P]epsi? " );
      caracter( bebida );
      if( *bebida != 'p' ) {
        *bebida = 'c';
      }
    }
    switch( *bebida ) {
      case 'a': preco = BEB_GARRAFA_AGUA; break;
      case 'v': preco = BEB_GARRAFA_VINHO; break;
      case 'i': case 'c': case 'p': preco = BEB_REFRIGERANTE; break;
    }
    *conta += preco;
  }
}

// Função que permite ao utilizador escolher entre uma das sobremesas existentes
void escolherSobremesa( char *sobremesa, double *conta ) {
  double preco = 0;
  printf( "\n  Sobremesa, [s]im? " );
  caracter( sobremesa );
  if( *sobremesa != 's' ) {
    *sobremesa = '_';
  } else {
    printf( "    Temos...\n\n      [D]oce da casa\n      [M]ousse de chocolate\n      [F]ruta fresca\n      [B]aba de camelo\n      [S]alada de fruta\n\n    Qual pretende? " );
    caracter( sobremesa );
    while( *sobremesa != 'd' && *sobremesa != 'm' && *sobremesa != 'f' && *sobremesa != 'b' && *sobremesa != 's' ) {
      printf( "      Diga? " );
      caracter( sobremesa );
    }
    switch( *sobremesa ) {
      case 'd': preco = SOBR_DOCE_CASA; break;
      case 'm': preco = SOBR_MOUSSE_CHOCOLATE; break;
      case 'f': preco = SOBR_FRUTA_FRESCA; break;
      case 'b': preco = SOBR_BABA_CAMELO; break;
      case 's': preco = SOBR_SALADA_FRUTA; break;
    }
    *conta += preco;
  }
}

// Função que permite ao utilizador escolher se quer café ou não
void escolherCafe( char *cafe, double *conta ) {
  printf( "\n  Cafe, [s]im? " );
  caracter( cafe );
  if( *cafe != 's' ) {
    *cafe = '_';
  } else {
    *conta += CAFE;
  }
}

// Função que permite ao utilizador escolher se quer o contribuinte no talão
void questionarFatura( char *fatura, char *contribuinte ) {
  printf( "\n  Fatura, [s]im? " );
  caracter( fatura );
  if( *fatura != 's' ) {
    *fatura = 'n';
    contribuinte = "XXXXXXXXX";
  } else {
    printf( "    NIF? " );
    scanf( "%s", contribuinte );
    while( strlen( contribuinte ) != 9 ) {
      printf( "      Podia repetir? " );
      scanf( "%s", contribuinte );
    }
  }
}


char * carimboTemporal() {
  static char carimbo[ 16 ];
  char ano[ 8 ], mes[ 8 ], dia[ 8 ], horas[ 8 ], minutos[ 8 ], segundos[ 8 ];
  int _ano, _mes, _dia, _horas, _minutos, _segundos;
  time_t _agora;
  time( &_agora );
  struct tm *local = localtime( &_agora );
  _ano = local -> tm_year + 1900;
  _mes = local -> tm_mon + 1;
  _dia = local -> tm_mday;
  _horas = local -> tm_hour;
  _minutos = local -> tm_min;
  _segundos = local -> tm_sec;

  // Ano
  sprintf( ano, "%d", _ano );
  strcat( carimbo, ano );

  // Mês
  if( _mes < 10 ) {
    strcat( carimbo, "0" );
  }
  sprintf( mes, "%d", _mes );
  strcat( carimbo, mes );

  // Dia
  if( _dia < 10 ) {
    strcat( carimbo, "0" );
  }
  sprintf( dia, "%d", _dia );
  strcat( carimbo, dia );

  // Separador
  strcat( carimbo, "_" );

  // Horas
  if( _horas < 10 ) {
    strcat( carimbo, "0" );
  }
  sprintf( horas, "%d", _horas );
  strcat( carimbo, horas );

  // Minutos
  if( _minutos < 10 ) {
    strcat( carimbo, "0" );
  }
  sprintf( minutos, "%d", _minutos );
  strcat( carimbo, minutos );

  // Segundos
  if( _segundos < 10 ) {
    strcat( carimbo, "0" );
  }
  sprintf( segundos, "%d", _segundos );
  strcat( carimbo, segundos );

  // Separador
  //strcat( carimbo, ".txt" );

  // Devolver carimbo
  //printf( "\n  > Carimbo: %s\n", carimbo );
  return carimbo;
}




void processarPedido( struct pedido pedido ) {
  FILE *ficheiro;
  char caracter, caminho[ 250 ] = "C:\\Users\\pedro\\AppData\\Roaming\\Restaurante\\";
  // char *carimbo = carimboTemporal();
  char *carimbo = "teste";
  strcat( caminho, carimbo );
  if( pedido.fatura == 's' ) {
    strcat( caminho, "_fatura.txt" );
  } else {
    strcat( caminho, "_recibo.txt" );
  }
  ficheiro = fopen( caminho, "w+" );
  fputs( "\n  ******************************************", ficheiro );
  fputs( "\n  ** GATUNICE < RESTAURANTE E BAR **********", ficheiro );
  fputs( "\n  ** ", ficheiro );
  if( pedido.fatura == 's' ) {
    fputs( "FATURA > ", ficheiro );
    fputs( pedido.contribuinte, ficheiro );
    fputs( " ********************", ficheiro );
  } else {
    fputs( "RECIBO > CONSUMIDOR FINAL *************", ficheiro );
  }
  fputs( "\n  ******************************************\n  ** ", ficheiro );
  if( pedido.menu != '_' ) {
    switch( pedido.menu ) {
      case 'c': fprintf( ficheiro, "Menu Carne ................... %.2f", MENU_CARNE ); break;
      case 'p': fprintf( ficheiro, "Menu Peixe ................... %.2f", MENU_PEIXE ); break;
      case 'v': fprintf( ficheiro, "Menu Vegetariano ............. %.2f", MENU_VEGETARIANO ); break;
      case 'i': fprintf( ficheiro, "Menu Infantil ................ %.2f", MENU_INFANTIL ); break;
    }
  }
  if( pedido.prato != '_' ) {
    switch( pedido.prato ) {
      case 'f': fprintf( ficheiro, "Bifes de frango panados ...... %.2f", BIFES_FRANGO_PANADOS ); break;
      case 'c': fprintf( ficheiro, "Carne de vaca estufada ....... %.2f", CARNE_VACA_ESTUFADA ); break;
      case 'b': fprintf( ficheiro, "Bacalhau assado .............. %.2f", BACALHAU_ASSADO ); break;
      case 'g': fprintf( ficheiro, "Bife grelhado ................ %.2f", BIFE_GRELHADO ); break;
      case 's': fprintf( ficheiro, "Salmao grelhado .............. %.2f", SALMAO_GRELHADO ); break;
      case 'o': fprintf( ficheiro, "Ovo estrelado ................ %.2f", OVO_ESTRELADO ); break;
    }
  }
  fputs( "$ **", ficheiro );
  if( pedido.acompanhamento != '_' ) {
    fputs( "\n  **   ", ficheiro );
    switch( pedido.acompanhamento ) {
      case 'a': fprintf( ficheiro, "c/ arroz branco .......... + %.2f", ACOMP_ARROZ_BRANCO ); break;
      case 'b': fprintf( ficheiro, "c/ batata assada ......... + %.2f", ACOMP_BATATA_ASSADA ); break;
      case 'f': fprintf( ficheiro, "c/ batata frita .......... + %.2f", ACOMP_BATATA_FRITA ); break;
      case 'm': fprintf( ficheiro, "c/ migas ................. + %.2f", ACOMP_MIGAS ); break;
    }
    fputs( "$ **", ficheiro );
  }
  if( pedido.bebida != '_' ) {
    fputs( "\n  ** ", ficheiro );
    switch( pedido.bebida ) {
      case 'a': fprintf( ficheiro, "Garrafa de agua (75cl) ....... %.2f", BEB_GARRAFA_AGUA ); break;
      case 'v': fprintf( ficheiro, "Garrafa de vinho ............. %.2f", BEB_GARRAFA_VINHO ); break;
      case 'i': fprintf( ficheiro, "Iced Tea ..................... %.2f", BEB_REFRIGERANTE ); break;
      case 'c': fprintf( ficheiro, "Coca-Cola .................... %.2f", BEB_REFRIGERANTE ); break;
      case 'p': fprintf( ficheiro, "Pepsi ........................ %.2f", BEB_REFRIGERANTE ); break;
    }
    fputs( "$ **", ficheiro );
  }
  if( pedido.sobremesa != '_' ) {
    fputs( "\n  ** ", ficheiro );
    switch( pedido.sobremesa ) {
      case 'd': fprintf( ficheiro, "Doce da casa ................. %.2f", SOBR_DOCE_CASA ); break;
      case 'm': fprintf( ficheiro, "Mousse de chocolate .......... %.2f", SOBR_MOUSSE_CHOCOLATE ); break;
      case 'f': fprintf( ficheiro, "Fruta fresca ................. %.2f", SOBR_FRUTA_FRESCA ); break;
      case 'b': fprintf( ficheiro, "Baba de camelo ............... %.2f", SOBR_BABA_CAMELO ); break;
      case 's': fprintf( ficheiro, "Salada de fruta .............. %.2f", SOBR_SALADA_FRUTA ); break;
    }
    fputs( "$ **", ficheiro );
  }
  if( pedido.cafe != '_' ) {
    fputs( "\n  ** ", ficheiro );
    fprintf( ficheiro, "Cafe ......................... %.2f", CAFE );
    fputs( "$ **", ficheiro );
  }
  fprintf( ficheiro, "\n  ******************************************" );
  if( pedido.total >= 10 ) {
    fprintf( ficheiro, "\n  ** TOTAL ....................... %.2f$ **", pedido.total );
  } else {
    fprintf( ficheiro, "\n  ** TOTAL ........................ %.2f$ **", pedido.total );
  }

  fprintf( ficheiro, "\n  ******************************************" );
  fclose( ficheiro );

  if( ( ficheiro = fopen( caminho, "r" ) ) != NULL ) {
    caracter = fgetc( ficheiro );
    while( caracter != EOF ) {
      printf( "%c", caracter );
      caracter = fgetc( ficheiro );
    }
    fclose( ficheiro );
  }
}







void main() {
  char repetir;

  cabecalho();
  do {
    struct pedido pedido;
    apresentacao();
    escolherMenuOuCarta( &pedido.tipo );
    if( pedido.tipo == 'm' ) {
      pedido.prato = '_';
      pedido.acompanhamento = '_';
      escolherMenu( &pedido.menu, &pedido.total );
    } else {
      pedido.menu = '_';
      escolherPrato( &pedido.prato, &pedido.total );
      escolherAcompanhamento( &pedido.acompanhamento, &pedido.total );
    }
    escolherBebida( &pedido.bebida, &pedido.total );
    escolherSobremesa( &pedido.sobremesa, &pedido.total );
    escolherCafe( &pedido.cafe, &pedido.total );
    questionarFatura( &pedido.fatura, pedido.contribuinte );
    processarPedido( pedido );
  } while( repetir == 's' );
  sair();
}
