import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		BigInteger catalan[] = new BigInteger[1001];
		catalan[0] = BigInteger.ONE;
		for (int i = 1; i < 1001; i++) {
			catalan[i] = BigInteger.ZERO;
			for (int j = 0; j < i; j++) {
				catalan[i] = catalan[i]
						.add(catalan[j].multiply(catalan[i-1-j]));
			}
		}
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			System.out.println(catalan[cin.nextInt()]);
		}
		cin.close();
	}
}
