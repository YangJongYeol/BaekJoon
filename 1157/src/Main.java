import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = sc.next();
        char[] alphabet = new char[(int)'z'-(int)'a'+1];

        for (int i=0; i<str.length(); i++) {
            if ((int)str.charAt(i) >= (int)'a')
                alphabet[(int)str.charAt(i)-(int)'a']++;
            else
                alphabet[(int)str.charAt(i)-(int)'A']++;
        }

        int maxNum = 0;
        int maxAlph = -1;
        for (int i=0; i<alphabet.length; i++) {
            if (alphabet[i] > maxNum) {
                maxAlph = i;
                maxNum = alphabet[i];
            }
        }

        for (int i=0; i<alphabet.length; i++) {
            if (alphabet[i] == maxNum && maxAlph != i) {
                System.out.println("?");
                return;
            }
        }

        System.out.println((char)(maxAlph+(int)'A'));
    }
}