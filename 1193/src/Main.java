import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int stage = 1;
        int num = sc.nextInt();
        int range = 1;

        while (true) {
            if (range >= num) {
                range -= stage;
                break;
            }
            stage ++;

            range += stage;
        }

        num = num - range;
        stage ++;

        if (stage%2==1)
            System.out.println(num+"/"+(stage-num));
        else
            System.out.println((stage-num)+"/"+num);
    }
}