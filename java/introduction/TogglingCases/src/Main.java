import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();

        for (int i = 0; i < line.length(); i++) {
            char ch = line.charAt(i);

            if (Character.isLowerCase(ch)) {
                System.out.print(Character.toUpperCase(ch));
            } else if (Character.isUpperCase(ch)) {
                System.out.print(Character.toLowerCase(ch));
            } else {
                System.out.print(ch);
            }

            if (i + 1 == line.length()) {
                System.out.println();
            }
        }
    }
}