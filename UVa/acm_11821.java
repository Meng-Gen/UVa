import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int numTestcases = cin.nextInt();
		for (int caseId = 0; caseId < numTestcases; caseId++) {
			BigDecimal sum = BigDecimal.ZERO;
			while (true) {
				String numberString = cin.next();
				
				if (numberString.compareTo("0") == 0) {
					String sumString = sum.toPlainString()
							.replaceAll("0*$", "");
					if (sumString.endsWith(".")) {
						sumString = sumString.replace(".", "");
					}
					System.out.println(sumString);
					break;
				}

				sum = sum.add(new BigDecimal(numberString));
			}
		}
		cin.close();
	}
}
