// Basnet, Himal
// hxb9428
// 2020-03-02

using System;
using System.IO;
using System.Text.RegularExpressions;

//----------------------------------------------------------
public class hmwk_01
{
  static public void processToken( string token ) {

    string PatternTent = @"\+\$*[0-7g-n]+\^";
    string patternAitchPi = @"^[0-9a-fA-F]*\]\([Q-Zq-z]*$";
    string patternJuggle = @"\([N-Za-m]+#";

   Regex Re = new Regex(PatternTent);
   Regex re1 = new Regex(patternAitchPi);
   Regex re2 = new Regex(patternJuggle);

    if(Re.IsMatch(token))
      Console.WriteLine(">" + token + "< matches Tent.");
    else if (re1.IsMatch(token))
      Console.WriteLine(">" + token + "< matches AitchPi.");
    else if (re2.IsMatch(token))
      Console.WriteLine(">" + token + "< matches Juggle.");
    else
      Console.WriteLine(">" + token + "< does not match.");
  }

  //--------------------------------------------------------
  // DO NOT CHANGE anything below this line!
  static public void Main( string[] args )
  {
    Console.WriteLine( "processing tokens from " + args[ 0 ] + " ..." );

    foreach ( string line in File.ReadAllLines( args[ 0 ] ) ) {
      foreach ( string token in line.Split( (char []) null, StringSplitOptions.RemoveEmptyEntries ) ) {
        processToken( token );
      }
    }
  }
}
