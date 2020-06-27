// Basnet, Himal
// hxb9428
// 2020-03-02

#include <ctype.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getToken( FILE *fp );
regex_t regex1, regex2, regex3;
int result1, result2, result3;

//----------------------------------------------------------
void processToken( char *token )
{
  result1 = regexec(&regex1, token, 0, NULL, 0);
  result2 = regexec(&regex2, token, 0, NULL, 0);
  result3 = regexec(&regex3, token, 0, NULL, 0);
  if(result1 == 0)
  {
    printf(">%s< matches Tent.\n",token);
  }else if(result2 == 0)
  {
    printf(">%s< matches AitchPi.\n",token);
  }else if(result3 == 0)
  {
    printf(">%s< matches Juggle.\n",token);
  }
  else
  {
    printf(">%s< does not match.\n",token);
  }
}

//----------------------------------------------------------
int main( int argc, char *argv[] )
{

  regcomp(&regex1, "\\+\\$*[0-7g-n]+\\^", REG_EXTENDED);
  regcomp(&regex2, "^[0-9a-fA-F]*\\]\\([Q-Zq-z]*$", REG_EXTENDED);
  regcomp(&regex3, "\\([N-Za-m]+#", REG_EXTENDED);
  
  // DO NOT CHANGE anything below this line in main()!
  if ( argc > 1 ) {
    printf( "processing tokens from %s ...\n", argv[1] );

    FILE *fp = fopen( argv[1], "r" );
    char *token = NULL;

    if ( fp != NULL ) {
      while ( token = getToken( fp ) ) {
        processToken( token );
        free( token );
      }

      fclose( fp );
    } else {
      printf( "unable to open %s?\n", argv[1] );
    }
  } else {
    printf( "No input file specified.\n" );
  }
}

//----------------------------------------------------------
// DO NOT CHANGE anything below this line!
#define MAX_TOKEN_SIZE (1024)

char *getToken( FILE *fp )
{
  char token[ MAX_TOKEN_SIZE+1 ];
  int  i  = 0;

  while ( i < MAX_TOKEN_SIZE ) {
    int ch = fgetc( fp );

    if ( ch == EOF ) { break; }

    if ( isspace( ch ) ) {
      if ( i == 0 ) { continue; }
      break;
    }

    token[ i++ ] = ch;
  }

  if ( i == 0 ) { return NULL; }

  token[ i ] = '\0';

  return strdup( token );
}

//----------------------------------------------------------