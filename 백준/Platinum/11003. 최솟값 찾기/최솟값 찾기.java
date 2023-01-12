import java.io.*;
import java.util.*;

public class Main {
    static class Node {
        int value;
        int index;

        Node(int value, int index){
            this.value = value;
            this.index = index;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        Deque<Node> deque = new LinkedList<Node>();

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            int a = Integer.parseInt(st.nextToken());

            while(!deque.isEmpty() && deque.getLast().value > a){
                deque.removeLast();
            }

            deque.addLast(new Node(a, i));

            if(deque.getFirst().index < i-L+1){
                deque.removeFirst();
            }

            bw.write(deque.getFirst().value + " ");
        }
        
        
        bw.flush(); //남아있는 데이터 모두 출력
        bw.close(); //스트림 닫기
    }
}