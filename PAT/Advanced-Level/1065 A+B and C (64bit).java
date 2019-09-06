import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int i = 1; i <= T; i++) {
            BigInteger A = scanner.nextBigInteger();
            BigInteger B = scanner.nextBigInteger();
            BigInteger C = scanner.nextBigInteger();
            System.out.printf("Case #%d: %s\n", i, A.add(B).compareTo(C) > 0 ? "true" : "false");
        }
        scanner.close();
    }

}
