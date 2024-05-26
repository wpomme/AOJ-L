import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();

        List<int> ret;
        for (int j = 1; j < x; j++) {
            ret.add(j);
        }

        int[] ret = new int[0];

        int c = 0;

        for (int i = 1; i < x; i++) {
            if (i % 3 == 0) {
                ret[c] = i;
                c++;
                continue;
            }
            int n = i;
            while (n > 10) {
                if (n == 3) {
                    ret[c] = i;
                    c++;
                    break;
                }
                n = n % 10;
            }
        }
    }
}