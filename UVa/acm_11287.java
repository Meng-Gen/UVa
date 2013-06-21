import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		initPrimeTable();
		
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			long p = cin.nextLong();
			long a = cin.nextLong();
			if (p == 0 || a  == 0) {
				break;
			}

			if (isPrime(p)) {
				System.out.println("no");
			} else if (BigInteger.valueOf(a).modPow(BigInteger.valueOf(p), 
					BigInteger.valueOf(p)).compareTo(BigInteger.valueOf(a)) == 0) {
				System.out.println("yes");
			} else {
				System.out.println("no");
			}
		}
		cin.close();
	}
	
	private static void initPrimeTable() {
		Boolean visited[] = new Boolean[32000];
		for (int i = 0; i < 32000; i++) {
			visited[i] = false;
		}
		int currPos = 0;
		for (int i = 2; i < 32000; i++) {
			if (!visited[i]) {
				prime[currPos] = i;
				currPos++;
				for (int j = i + i; j < 32000; j += i) { 
					visited[j] = true;
				}
			}
		}
	}
	
	private static Boolean isPrime(long n) {
		for (int i = 0; i < 3432 && (prime[i] * prime[i] <= n); i++) {
			if (n == prime[i]) {
				return true;
			}
			if (n % prime[i] == 0) {
				return false;
			}
		}
		return true;
	}
	
	private static long prime[] = new long[3432];
}
