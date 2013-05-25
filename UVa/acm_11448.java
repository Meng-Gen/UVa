import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int numTestcases = cin.nextInt();
		for (int i = 0; i < numTestcases; i++) {
			System.out.println(cin.nextBigInteger()
					.subtract(cin.nextBigInteger()).toString());
		}
		cin.close();
	}
}
