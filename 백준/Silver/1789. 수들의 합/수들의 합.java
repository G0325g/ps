import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long S = sc.nextLong();
        long num = 0;
        long i;
        for(i=1; ;i++)
        {
            num+=i;
            if(num>S) break;
        }
        System.out.println(i-1);
    }
}