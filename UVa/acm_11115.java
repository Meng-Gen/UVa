import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int N = cin.nextInt();
			int D = cin.nextInt();
			if (N == 0 && D == 0) {
				break;
			}
			System.out.println(BigInteger.valueOf(N).pow(D));
		}
		cin.close();
	}
}
