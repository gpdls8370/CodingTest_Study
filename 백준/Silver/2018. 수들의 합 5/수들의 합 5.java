import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int start = 1;
        int end = 1;
        int sum = 1;
        int result = 1; //end가 N일 경우 포함

        while(end < N){
            if(sum < N){
                end++;
                sum += end;
            }
            else if(sum > N){
                sum -= start;
                start++;
            }
            else{
                result++;
                end++;
                sum += end;
            }
        }
        System.out.println(result);
    }
}