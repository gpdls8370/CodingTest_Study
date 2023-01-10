import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
        int a = 0;
        int b = N-1;
        int count = 0;

        while(a < b){
            if(arr[a] + arr[b] < M){
                a++;
            }
            else if(arr[a] + arr[b] > M){
                b--;
            }
            else{
                count++;
                a++;
                b--;
            }
        }
        System.out.println(count);
    }
}