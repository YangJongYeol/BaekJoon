import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashSet<String> hs = new HashSet<>();

        int T = sc.nextInt();
        for (int i=0; i<T; i++) {
            hs.add(sc.next());
        }

        String[] array = new String[hs.size()];
        hs.toArray(array);

        Arrays.sort(array, Comparator.comparingInt(String::length));

        for (int i=0; i<array.length; i++) {
            int j=i+1;
            for (; j<array.length; j++) {
                if (array[i].length() != array[j].length())
                    break;
            }
            Arrays.sort(array,i,j);
            i = j-1;
        }

        for (int i=0; i<array.length; i++)
            System.out.println(array[i]);

    }
}