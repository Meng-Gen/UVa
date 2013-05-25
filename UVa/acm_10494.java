import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			BigInteger a = cin.nextBigInteger();
			String op = cin.next();
			BigInteger b = cin.nextBigInteger();
			if (op.compareTo("/") == 0) {
				System.out.println(a.divide(b));
			} else if (op.compareTo("%") == 0) {
				System.out.println(a.mod(b));
			}
		}
		cin.close();
	}
}
