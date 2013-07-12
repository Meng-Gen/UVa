import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int numTestcases = cin.nextInt();
		for (int caseId = 1; caseId <= numTestcases; caseId++) {
			String dna = cin.next();
			BigInteger number = new BigInteger(dna.replace('A', '0')
					.replace('C', '1').replace('G', '2').replace('T', '3'), 4);
			System.out.printf("Case %d: (%s:%s)\n", 
					caseId, dna.length(), number.toString());
		}
		cin.close();
	}
}
