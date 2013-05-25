import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			System.out.println(cin.nextBigInteger()
					.multiply(cin.nextBigInteger()).toString());
		}
		cin.close();
	}
}
