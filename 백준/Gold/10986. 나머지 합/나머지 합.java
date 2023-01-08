import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        //(A+B) % M = ((A % M) + (B % M)) % M
        //나머지가 a인 두 구간을 빼면 나머지가 0 즉, 나누어 떨어지는 구간을 구할 수 있음
        long S[] = new long[N+1];
        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=N;i++){
            S[i] = S[i-1] + Integer.parseInt(st.nextToken());
        }

        long R[] = new long[M];
        //배열 값을 나머지로 갱신 + 나머지 배열 값 갱신
        for(int i=1;i<=N;i++){
            int remainder = (int) (S[i] % M);
            R[remainder]++;
        }

        //답 = 나머지가 0인 경우 + 나머지가 같은 합 배열에서 2가지를 뽑는 경우
        long result = R[0];
        for(int i=0;i<M;i++){
            result += R[i] * (R[i]-1) / 2;
        }

        System.out.println(result);
    }
}