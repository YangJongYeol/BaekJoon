import java.util.Scanner;

public class Main {
    public static int checkActivateCount(long x, long y) {
        int k;

        for (int i=2; ;i++) {
            if (Math.pow(i,2)-i >= (y-x)) {
                k = i-1;
                break;
            }
        }

        if (Math.pow(k,2)>=(y-x))
            return 2*k-1;
        else
            return 2*k;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        StringBuilder stringBuilder = new StringBuilder();
        for (int i=0; i<T; i++) {
            long x = sc.nextLong();
            long y = sc.nextLong();

            stringBuilder.append(checkActivateCount(x, y)).append("\n");
        }

        System.out.println(stringBuilder);
    }
}
