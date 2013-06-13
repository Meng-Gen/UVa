import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		initFactorialNumber();
		
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			int k = cin.nextInt();
			if (n == 0 && k == 0) {
				break;
			}
			System.out.println(factorial[n+k-1].divide(factorial[n]).divide(factorial[k-1])
					.mod(BigInteger.valueOf(1000000)));
		}
		cin.close();
	}
	
	private static void initFactorialNumber() {
		factorial[0] = BigInteger.ONE;
		for (int i = 1; i < 201; i++) {
			factorial[i] = factorial[i-1].multiply(BigInteger.valueOf(i));
		}
	}
	
	private static BigInteger factorial[] = new BigInteger[201];
}
