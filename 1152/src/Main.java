import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int count;
        String str = sc.nextLine();
        String[] sentence = str.split(" ");

        count = sentence.length;

        if (count>0 && sentence[0].equals(""))
            count--;

        System.out.println(count);
    }
}
