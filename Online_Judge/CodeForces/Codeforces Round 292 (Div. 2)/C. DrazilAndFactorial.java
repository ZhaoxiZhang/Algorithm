import java.util.Arrays;
import java.util.Scanner;
import static java.lang.System.out;

public class DrazilAndFactorial {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		scan.nextLine();
		String s = scan.nextLine();
		s = s.replaceAll("0", "");
		s = s.replaceAll("1", "");
		s = s.replaceAll("4", "223");
		s = s.replaceAll("6", "53");
		s = s.replaceAll("8", "7222");
		s = s.replaceAll("9", "7332");
		
		char[] c = s.toCharArray();
		
		Arrays.sort(c);
		
		for (int i = 0;i < c.length;i++) {
			out.print(c[c.length-1-i]);
		}
		out.println();
	}
}
