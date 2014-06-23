import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		initFibonacciNumber();
		
		final Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			final BigInteger a = cin.nextBigInteger();
			final BigInteger b = cin.nextBigInteger();
			if ((a.compareTo(BigInteger.ZERO) == 0) && (b.compareTo(BigInteger.ZERO) == 0)) {
				break;
			}
			
			int count = 0;
			for (int i = 0; i< FIBONACCI_COUNT; i++) {
				BigInteger n = fibonacci[i];
				if (n.compareTo(a) < 0) {
					continue;
				}
				if (n.compareTo(b) > 0) {
					break;
				}
				count++;
			}
			System.out.println(count);
		}
		cin.close();
	}
	
	private static void initFibonacciNumber() {
		fibonacci[0] = BigInteger.ONE;
		fibonacci[1] = BigInteger.valueOf(2);
		for (int i = 2; i < FIBONACCI_COUNT; i++) {
			fibonacci[i] = fibonacci[i-1].add(fibonacci[i-2]);
		}
	}
	
	private static final int FIBONACCI_COUNT = 500;
	private static BigInteger fibonacci[] = new BigInteger[FIBONACCI_COUNT];
}