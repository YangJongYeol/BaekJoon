import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num = sc.nextInt();
        int ten, one;
        int modifiedNum = num;
        int count = 0;

        while (true) {
            ten = modifiedNum/10;
            one = modifiedNum%10;

            modifiedNum = ten+one;
            modifiedNum = one*10+modifiedNum%10;
            count++;

            if (modifiedNum == num) {
                System.out.println(count);
                break;
            }
        }
    }
}
