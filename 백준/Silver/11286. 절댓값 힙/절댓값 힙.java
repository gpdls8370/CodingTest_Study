import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> {
            int absA = Math.abs(a);
            int absB = Math.abs(b);

            if(absA == absB)
                return a > b ? 1 : -1;
            else
                return absA - absB;
        });

        int N = Integer.parseInt(br.readLine());
        for(int i=0;i<N;i++){
            int x = Integer.parseInt(br.readLine());

            if(x == 0){
                if(pq.isEmpty()){
                    System.out.println(0);
                }
                else {
                    System.out.println(pq.poll());
                }
            } 
            else{
                pq.offer(x);
            }
        }
    }

    /*
    Comparator<Integer> comparator = new Comparator<Integer>() {
        @Override
        public int compare(int a, int b){
            int absA = Math.abs(a);
            int absB = Math.abs(b);

            //(리턴값) 양수:a가 더 큼, 0:같음, 음수:b가 더 큼
            if(absA == absB) return a > b ? 1 : -1; //절댓값 같으면 음수가 작은거
            else return absA - absB;                //절댓값으로 정렬
        }
    }*/
}