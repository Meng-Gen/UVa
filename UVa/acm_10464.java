import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int numTestcases = cin.nextInt();
		for (int caseId = 0; caseId < numTestcases; caseId++) {
			// Hack: |.| is an illegal representation for |BigDecimal|. 
			String xString = cin.next();
			BigDecimal x = (xString.compareTo(".") == 0) ? 
					BigDecimal.ZERO : new BigDecimal(xString);
			
			String yString = cin.next();
			BigDecimal y = (yString.compareTo(".") == 0) ?
					BigDecimal.ZERO : new BigDecimal(yString);

			// |stripTrailingZeros| may introduce WA.
			// Test case: -1111.111 1111.111
			String rv = x.add(y).toPlainString().replaceAll("0*$", "");
			if (rv.indexOf('.') < 0) {
				rv = ".0";
			}
			if (rv.endsWith(".")) {
				rv = rv + "0";
			} 
			if (rv.startsWith(".")) {
				rv = "0" + rv;
			}
			
			System.out.println(rv);
		}
		cin.close();
	}
}
