import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		
		while (cin.hasNext()) {
			BigDecimal x = cin.nextBigDecimal();
			int n = cin.nextInt();
			String rv = x.pow(n).stripTrailingZeros().toPlainString();
			if (rv.startsWith("0.")) {
				rv = rv.substring(1);
			}
			System.out.println(rv);
		}
		cin.close();
	}
}
