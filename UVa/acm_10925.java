import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		int caseId = 1;
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int numItems = cin.nextInt();
			int numFriends = cin.nextInt();
			if (numItems == 0 && numFriends == 0) {
				break;
			}
			BigInteger sum = BigInteger.ZERO;
			for (int i = 0; i < numItems; i++) {
				sum = sum.add(cin.nextBigInteger());
			}
			BigInteger average = sum.divide(BigInteger.valueOf(numFriends));
			String output = "Bill #" + caseId + " costs " + sum.toString() 
					+ ": each friend should pay " + average.toString();
			System.out.println(output);
			System.out.println();
			caseId++;
		}
		cin.close();
	}
}
