// Basnet, Himal
// hxb9428
// 2020-04-01

#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

//----------------------------------------------------------
regex r1("^(%|\\*)(([%][%])*|([\\*][\\*])*|([\\*][%])*|([%][\\*])*)*([pJ]+|[p]+(?:pay)|[J]+(?:JAY))$");
//regex r2("^(\\+|-|:)([A-F0-9][A-F0-9])+(\\W(?!\1))$");
regex r2("^(\\+([0-9A-F][0-9A-F])*(-|:)|-([0-9A-F][0-9A-F])*(\\+|:)|:([0-9A-F][0-9A-F])*(-|\\+))$");
regex r3("^\\|([AEIOU]+(?:\\*)|[aeiou]+(?:=)|\\$)$");

smatch m1,m2,m3;

void processToken( string token )
{
  if(regex_match(token, r1))
    cout << ">"+token+"< matches PayJay." << endl;
  else if(regex_match(token, r2))
    cout << ">"+token+"< matches Rattle." << endl;
  else if(regex_match(token, r3))
    cout << ">"+token+"< matches Tork." << endl;
  else
    cout << ">"+token+"< does not match." << endl;
}

//----------------------------------------------------------
// DO NOT CHANGE anything below this line!
int main( int argc, char *argv[] )
{
  if ( argc > 1 ) {
    cout << "processing tokens from " << argv[ 1 ] << " ...\n";

    ifstream inputFile;
    string   token;

    inputFile.open( argv[ 1 ] );

    if ( inputFile.is_open() ) {
      while ( inputFile >> token ) {
        processToken( token );
      }
      inputFile.close();
    } else {
      cout << "unable to open " << argv[ 1 ] << "?\n";
    }
  } else {
    cout << "No input file specified.\n";
  }
}

//----------------------------------------------------------
