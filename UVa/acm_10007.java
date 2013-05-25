import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		initFactorialNumber();
		
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			if (n == 0) {
				break;
			}
			// The answer = #(tree) * n! = C(n) * n! = (2n)!/(n+1)!
			System.out.println(factorial[2*n].divide(factorial[n+1]));
		}
		cin.close();
	}
	
	private static void initFactorialNumber() {
		factorial[0] = BigInteger.ONE;
		for (int i = 1; i < 601; i++) {
			factorial[i] = factorial[i-1].multiply(BigInteger.valueOf(i));
		}
	}
	
	private static BigInteger factorial[] = new BigInteger[601];
}
