import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		final BigInteger kUpperBound = BigInteger.valueOf(Integer.MAX_VALUE); 
	
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			// We need to handle input in this way, otherwise WA
			String buffer = cin.nextLine();
			System.out.println(buffer);
			
			StringTokenizer tokens = new StringTokenizer(buffer);
			BigInteger a = new BigInteger(tokens.nextToken());
			String op = tokens.nextToken();
			BigInteger b = new BigInteger(tokens.nextToken());
			if (a.compareTo(kUpperBound) > 0) {
				System.out.println("first number too big");
			}
			if (b.compareTo(kUpperBound) > 0) {
				System.out.println("second number too big");
			}
			
			BigInteger rv = BigInteger.ZERO;
			if (op.compareTo("+") == 0) {
				rv = a.add(b);
			} else {
				rv = a.multiply(b);
			} 
			if (rv.compareTo(kUpperBound) > 0) {
				System.out.println("result too big");
			}
		}
		cin.close();
	}
}
