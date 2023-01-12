import java.io.*;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Integer> stack = new Stack<>();

        //BufferedWriter를 사용하면 버퍼가 일정량 이상 찼을때 비정기적으로 flush가 되기 때문에 "NO"출력 전에 출력초과가 날 수 있음
        StringBuilder sb = new StringBuilder(); //StringBuffer는 멀티스레드에서 유리

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