import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stack = new Stack<>();

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int[] answer = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        stack.push(0);
        for(int i=1;i<N;i++){
            while(!stack.isEmpty() && arr[i] > arr[stack.peek()]){
                //오큰수 찾음
                answer[stack.pop()] = arr[i];
            }
            stack.push(i);
        }

        while(!stack.isEmpty()){
            answer[stack.pop()] = -1;
        }
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        for(int i=0;i<N;i++){
            bw.write(answer[i] + " ");
        }
        bw.close();
    }
}