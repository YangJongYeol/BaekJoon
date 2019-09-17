import java.util.Scanner;

public class Main {
    static boolean hanNumber(int n){
        if (n < 10) {
            return true;
        }

        int length = (int)(Math.log10(n)+1);
        int[] seq = new int[length];

        for (int i=0; i<length ;i++) {
            seq[i] = n%10;
            n = n/10;
        }

        int sub = seq[0]-seq[1];

        for (int i=0; i<seq.length-1; i++) {
            if (seq[i]-seq[i+1] != sub)
                return false;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        int count = 0;

        for (int i=1; i<=num; i++){
            if (hanNumber(i))
                count++;
        }

        System.out.println(count);
    }
}
