import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			BigInteger factorial = BigInteger.ONE;
			for (int i = 1; i <= n; i++)
			{
				factorial = factorial.multiply(BigInteger.valueOf(i));
			}
			System.out.println(n + "!");
			System.out.println(factorial.toString());
		}
		cin.close();
	}
}
