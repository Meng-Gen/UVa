import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int n = cin.nextInt();
			BigInteger a = cin.nextBigInteger();
			BigInteger power = a;
			BigInteger sum = BigInteger.ZERO;
			for (int i = 1; i <= n; i++) {
				sum = sum.add(BigInteger.valueOf(i).multiply(power));
				power = power.multiply(a);
			}
			System.out.println(sum.toString());
		}
		cin.close();
	}
}
