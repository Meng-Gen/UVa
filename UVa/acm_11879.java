import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			BigInteger n = cin.nextBigInteger();
			if (n.compareTo(BigInteger.ZERO) == 0) {
				break;
			}
			BigInteger r = n.mod(BigInteger.valueOf(17));
			if (r.compareTo(BigInteger.ZERO) == 0) {
				System.out.println("1");
			} else {
				System.out.println("0");
			}
		}
		cin.close();
	}
}
