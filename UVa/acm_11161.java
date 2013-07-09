import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		initFibonacciNumber();
		
		int caseId = 1;
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			if (n == 0) {
				break;
			}
			BigInteger median = fibonacci[n+2].subtract(BigInteger.valueOf(2))
					.subtract(fibonacci[n].divide(BigInteger.valueOf(2)));
			System.out.println("Set " + caseId + ":");
			System.out.println(median);
			caseId++;
		}
		cin.close();
	}
	
	private static void initFibonacciNumber() {
		fibonacci[0] = BigInteger.ZERO;
		fibonacci[1] = BigInteger.ONE;
		for (int i = 2; i < 1510; i++) {
			fibonacci[i] = fibonacci[i-1].add(fibonacci[i-2]);
		}
	}
	
	private static BigInteger fibonacci[] = new BigInteger[1510];
}

