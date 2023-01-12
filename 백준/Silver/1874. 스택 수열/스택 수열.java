import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stack = new Stack<>();
        StringBuffer sb = new StringBuffer();

        int N = Integer.parseInt(br.readLine());
        int nextNum = 1;
        boolean possible = true;

        for(int i=0;i<N;i++){
            int target = Integer.parseInt(br.readLine());

            if(target >= nextNum){
                //원하는 숫자로 만들고
                while(target >= nextNum){
                    stack.push(nextNum++);
                    sb.append("+\n");
                }
                //꺼내기
                stack.pop();
                sb.append("-\n");
            }
            //원하는 숫자가 다음번호보다 작을때
            else{
                if(stack.peek() != target){
                    System.out.print("NO");
                    possible = false;
                    break;
                }
                else{
                    stack.pop();
                    sb.append("-\n");
                }
            }
        }

        if(possible) {
            System.out.print(sb);
        }
    }
}