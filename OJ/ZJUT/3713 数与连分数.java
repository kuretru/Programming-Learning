import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextLine()) {
            String text = scanner.nextLine();
            if ('[' == text.charAt(0)) {
                toFraction(text);
            } else {
                toContinued(text);
            }
        }
        scanner.close();
    }

    public static void toFraction(String text) {
        text = text.replace(";", ",")
                .replace("[", "")
                .replace("]", "");
        List<Long> data = new ArrayList<>();
        for (String s : text.split(",")) {
            data.add(Long.valueOf(s));
        }

        long numerator = 1L;
        long denominator = data.get(data.size() - 1);
        for (int i = data.size() - 2; i >= 0; i--) {
            numerator += data.get(i) * denominator;
            long tmp = denominator;
            denominator = numerator;
            numerator = tmp;
        }
        long tmp = denominator;
        denominator = numerator;
        numerator = tmp;

        for (int i = 2; i <= denominator; i++) {
            while (numerator % i == 0 && denominator % i == 0) {
                numerator /= 2;
                denominator /= 2;
            }
        }

        System.out.printf("%d/%d\n", numerator, denominator);
    }

    public static void toContinued(String text) {
        int index = text.indexOf("/");
        long numerator = Long.parseLong(text.substring(0, index));
        long denominator = Long.parseLong(text.substring(index + 1));

        List<Long> data = new ArrayList<>();
        while (numerator > denominator) {
            data.add(numerator / denominator);
            long tmp = numerator % denominator;
            numerator = denominator;
            denominator = tmp;
            if (1 == denominator) {
                data.add(numerator);
                break;
            }
        }

        System.out.printf("[%d;", data.get(0));
        for (int i = 1; i < data.size(); i++) {
            System.out.printf("%d%s", data.get(i), (i == data.size() - 1) ? "]\n" : ",");
        }
    }

}
