// Basnet, Himal
// hxb9428
// 2020-04-01

import java.nio.file.Paths;
import java.nio.file.Files;
import java.util.Arrays;

//----------------------------------------------------------
public class hmwk_02 {
  public static void processToken(String token) {
    if (token.matches("^(%|\\*)(([%][%])*|([\\*][\\*])*|([\\*][%])*|([%][\\*])*)*([pJ]+|[p]+(?:pay)|[J]+(?:JAY))$")) {
      System.out.println(">" + token + "< matches PayJay.");
    } else if (token.matches("^(\\+([0-9A-F][0-9A-F])*(-|:)|-([0-9A-F][0-9A-F])*(\\+|:)|:([0-9A-F][0-9A-F])*(-|\\+))$")) {
      System.out.println(">" + token + "< matches Rattle.");
    } else if (token.matches("^\\|([AEIOU]+(?:\\*)|[aeiou]+(?:=)|\\$)$")) {
      System.out.println(">" + token + "< matches Tork.");
    } else {
      System.out.println(">" + token + "< does not match.");
    }
  }

  // --------------------------------------------------------
  // DO NOT CHANGE anything below this line!
  public static void main(String[] args) {
    System.out.println("processing tokens from " + args[0] + " ...");

    try {
      Files.lines(Paths.get(args[0])).filter(line -> line.length() > 0)
          .forEachOrdered(line -> Arrays.stream(line.split("\\s+")).forEachOrdered(token -> processToken(token)));
    } catch (java.io.IOException e) {
      e.printStackTrace();
    }
  }
}

// ----------------------------------------------------------
