import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        for (int j = n; j > 0; j--) {
            if (j > 1) {
                System.out.print(nums[j - 1] + " ");
            } else {
                System.out.println(nums[j - 1]);
            }
        }
    }
}