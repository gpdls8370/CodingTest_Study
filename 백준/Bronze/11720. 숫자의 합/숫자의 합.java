import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int sum = 0;
        int N = sc.nextInt();
        
        //nextLine() 사용하려면 2번써서 한번은 버퍼에 있는 공백 지워줘야함
        String str = sc.next();
        char[] c = str.toCharArray();

        for(int i=0;i<N;i++){
            sum+= c[i] - '0';
        }

        System.out.print(sum);
    }
}