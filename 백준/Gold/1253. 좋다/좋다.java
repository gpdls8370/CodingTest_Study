import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        long[] arr = new long[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            arr[i] = Long.parseLong(st.nextToken());
        }
        Arrays.sort(arr);

        int count = 0;

        for(int i=0;i<N;i++){
            long target = arr[i];
            int a = 0;
            int b = N-1;

            while(a < b){
                if(arr[a] + arr[b] < target){
                    a++;
                }
                else if(arr[a] + arr[b] > target){
                    b--;
                }
                else{
                    //target을 값에 포함시키면 안됨
                    if(a != i && b != i){
                        count++;
                        break;
                    }
                    //target과 같으면 그냥 지나가기
                    //음수일 수도 있으니 둘다 고려
                    else if(a == i){
                        a++;
                    }
                    else{
                        b--;
                    }
                }
            }
        }
        System.out.println(count);
    }
}