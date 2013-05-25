import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			String digit = cin.next();
			String numLiteral = cin.next();
			if (digit.compareTo("0") == 0 && numLiteral.compareTo("0") == 0) {
				break;
			}
			numLiteral = numLiteral.replace(digit, "");
			if (numLiteral.length() > 0) {
				System.out.println(new BigInteger(numLiteral));
			} else {
				System.out.println("0");
			}
		}
		cin.close();
	}
}
