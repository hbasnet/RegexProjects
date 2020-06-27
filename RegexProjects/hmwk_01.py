# Basnet, Himal
# hxb9428
# 2020-03-02
#-----------------------------------------------------------
import re
import sys

#-----------------------------------------------------------
def processToken( token ) :
  patternTent = re.compile(r'\+\$*[0-7g-n]+\^')
  patternAitchPi = re.compile(r'^[0-9a-fA-F]*\]\([Q-Zq-z]*$')
  patternJuggle = re.compile(r'\([N-Za-m]+#')

  if(patternTent.match(token)):
    print('>' + token + '< matches Tent.')
  elif (patternAitchPi.match(token)):
    print('>' + token + '< matches AitchPi.')
  elif (patternJuggle.match(token)):
    print('>' + token + '< matches Juggle.')
  else:
    print('>' + token + '< does not match.')

#-----------------------------------------------------------
# DO NOT CHANGE anything below this line!
def main() :
  fName = sys.argv[ 1 ]
  print( 'processing tokens from ' + fName + ' ...' )

  with open( fName, 'r' ) as fp :
    lines = fp.read().replace( '\r', '' ).split( '\n' )

  for line in lines :
    for token in line.split() :
      processToken( token )

#-----------------------------------------------------------
# DO NOT CHANGE anything below this line!
if ( __name__ == '__main__' ) :
  main()

#-----------------------------------------------------------
