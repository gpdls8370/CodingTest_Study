import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        //또는 String arr[] = s.split(" ");

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        //배열 초기값은 0 / 0.0 / false / null
        long S[] = new long[N+1];

        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=N;i++){
            S[i] = S[i-1] + Integer.parseInt(st.nextToken());
        }

        for(int k=0;k<M;k++){
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());

            System.out.println(S[j] - S[i-1]);
        }
    }
}