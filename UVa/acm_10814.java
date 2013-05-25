import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int numTestcases = cin.nextInt();
		for (int i = 0; i < numTestcases; i++) {
			BigInteger p = cin.nextBigInteger();
			cin.next(); // Eat '/' character
			BigInteger q = cin.nextBigInteger();
			BigInteger gcd = getGCD(p, q); 
			p = p.divide(gcd);
			q = q.divide(gcd);
			System.out.println(p + " / " + q);
		}
		cin.close();
	}
	
	private static BigInteger getGCD(BigInteger a, BigInteger b) {
	    while (b.compareTo(BigInteger.ZERO) > 0) {
	        BigInteger t = b;
	        b = a.mod(t);
	        a = t;
	    }
	    return a;
	}
}
