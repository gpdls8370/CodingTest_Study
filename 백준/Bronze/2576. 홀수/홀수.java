import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int sum = 0;
        int min = 999999;
        for(int i=0;i<7;i++){
            int a = sc.nextInt();
            if(a%2 == 1){
                sum += a;
                if(a < min) min =a;
            }
        }
        if(sum == 0){
            System.out.print(-1);
        }
        else{
            System.out.println(sum);
            System.out.print(min);
        }
    }
}