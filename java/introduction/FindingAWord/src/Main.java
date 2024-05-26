import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word = sc.next();
        int counter = 0;

        while (sc.hasNext()) {
            String compared = sc.next();
            if (compared.equals("END_OF_TEXT")) {
                System.out.println(counter);
                break;
            }

            if (word.equalsIgnoreCase(compared)) {
                counter++;
            }
        }
    }
}