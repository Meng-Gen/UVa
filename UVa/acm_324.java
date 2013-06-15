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
			solve(n);
		}
		cin.close();
	}
	
	private static void initFactorialNumber() {
		factorial[0] = BigInteger.ONE;
		for (int i = 1; i < 370; i++) {
			factorial[i] = factorial[i-1].multiply(BigInteger.valueOf(i));
		}
	}
	
	private static void solve(int n) {
		int[] frequencies = new int[10];
		String factorialString = factorial[n].toString();
		for (int i = 0; i < factorialString.length(); i++) {
			frequencies[factorialString.charAt(i) - '0']++;
		}
		
		System.out.println(n + "! --");
		System.out.println(String.format(
				"   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d", 
				frequencies[0],
				frequencies[1],
				frequencies[2],
				frequencies[3],
				frequencies[4]));
		System.out.println(String.format(
				"   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d", 
				frequencies[5],
				frequencies[6],
				frequencies[7],
				frequencies[8],
				frequencies[9]));
	}
	
	private static BigInteger factorial[] = new BigInteger[370];
}
