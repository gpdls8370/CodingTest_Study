import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] a = new int[N];

        //int형은 long으로 쓰는 습관
        long sum = 0;
        long max = 0;

        for(int i=0;i<N;i++){
            a[i] = sc.nextInt();
            sum += a[i];
            if(a[i] > max) max = a[i];
        }

        //(A /max *100) + (B /max *100) / N -> (A+B) *100 /max /N
        //float로 연산되게 100.0
        System.out.print(sum * 100.0 / max / N);
    }
}