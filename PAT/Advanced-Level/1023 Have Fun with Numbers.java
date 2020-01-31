import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    static final BigInteger TEN = BigInteger.valueOf(10);

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger number = scanner.nextBigInteger();
        BigInteger doubled = number.multiply(BigInteger.valueOf(2));
        int[] count = new int[10];
        while (number.compareTo(BigInteger.ZERO) == 1) {
            count[number.mod(TEN).intValue()]++;
            number = number.divide(TEN);
        }
        number = doubled;
        while (number.compareTo(BigInteger.ZERO) == 1) {
            count[number.mod(TEN).intValue()]--;
            number = number.divide(TEN);
        }
        boolean result = true;
        for (int i = 0; i < 10; i++) {
            if (count[i] != 0) {
                result = false;
                break;
            }
        }
        System.out.println(result ? "Yes" : "No");
        System.out.println(doubled.toString());
        scanner.close();
    }

}
