import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);

		while (true) {
			String buffer = cin.next();
			if (buffer.compareTo("*") == 0) {
				break;
			}
			
			if (Character.isAlphabetic(buffer.charAt(0))) {
				String answer = String.format("%-22s%s", 
						buffer, formatNumber(convertWord(buffer)));
				System.out.println(answer);
			} else {
				String answer = String.format("%-22s%s", 
						convertWordNumber(buffer), formatNumber(buffer));
				System.out.println(answer);
			}
		}
		
		cin.close();
	}
	
	private static String convertWordNumber(String number) {
		ArrayList<Character> word = new ArrayList<Character>();
		BigInteger n = new BigInteger(number);
		while (!n.equals(BigInteger.ZERO)) {
			n = n.add(BigInteger.valueOf(-1));
			int r = n.mod(BigInteger.valueOf(26)).intValue();
			word.add((char)('a' + r));
			n = n.divide(BigInteger.valueOf(26));
		}
		Collections.reverse(word);
		
		StringBuilder builder = new StringBuilder();
		for (Character c : word) {
			builder.append(c);
		}		
		return builder.toString();
	} 
	
	private static String convertWord(String word) {
		BigInteger n = BigInteger.ZERO;
		for (int i = 0; i < word.length(); i++) {
			n = n.multiply(BigInteger.valueOf(26));
			n = n.add(BigInteger.valueOf(word.charAt(i) - 'a' + 1));			
		}
		return n.toString();
	}
	
	private static String formatNumber(String number) {
		StringBuilder builder = new StringBuilder();
		
		int numDigits = number.length();
		builder.append(number.charAt(0));
		for (int i = 1; i < numDigits; i++) {
			if ((numDigits - i) % 3 == 0) {
				builder.append(',');
			}
			builder.append(number.charAt(i));
		}
		
		return builder.toString();
	}
}
