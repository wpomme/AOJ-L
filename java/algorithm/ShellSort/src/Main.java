import java.util.*;

public class Main {
    public static int count = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> a = new ArrayList<Integer>();

        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }

        int m = 0;
        List<Integer> g = new ArrayList<Integer>();

        while (true) {
            m = 3 * m + 1;
            if (m > a.size()) {
                break;
            }
            g.add(m);
        }

        Collections.reverse(g);

        shellSort(a, n, g);

        System.out.println(g.size());

        for (int i = 0; i < g.size(); i++) {
            if (i == g.size() - 1) {
                System.out.println(g.get(i));
            } else {
                System.out.print(g.get(i) + " ");
            }
        }

        System.out.println(count);

        for (int i : a) {
            System.out.println(i);
        }
    }

    private static void shellSort(List<Integer> a, int n, List<Integer> g) {
        for(int i : g) {
            insertionSort(a, n, i);
        }
    }

    private static void insertionSort(List<Integer> a, int n, int g) {
        for (int i = g; i < n; i++) {
            int v = a.get(i);
            int j = i - g;
            while (j >=0 && a.get(j) > v) {
                a.set(j + g, a.get(j));
                j = j - g;
                count++;
            }
            a.set(j + g, v);
        }
    }
}