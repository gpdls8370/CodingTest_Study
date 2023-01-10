import java.io.*;
import java.util.*;

public class Main {
    static int[] key;
    static int[] targetKey;
    static int match;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int S = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        char[] arr = br.readLine().toCharArray();

        //A, C, G, T
        key = new int[4];
        targetKey = new int[4];
        match = 0;
        int count = 0;

        st = new StringTokenizer(br.readLine());
        for(int i=0;i<4;i++){
            targetKey[i] = Integer.parseInt(st.nextToken());

            //0개 이상일 때는 Add에 안잡히니까 값 증가시켜줘야 함
            if(targetKey[i] == 0){
                match++;
            }
        }

        //첫 key세팅
        for(int i=0;i<P;i++){
            add(arr[i]);
        }

        if(match == 4){
            count++;
        }

        for(int end=P;end<S;end++){
            int start = end - P;

            add(arr[end]);
            remove(arr[start]);

            if (match == 4){
                count++;
            }
        }

        System.out.println(count);
    }

    public static void add(char c){
        switch (c) {
            case 'A':
                key[0]++;
                if (key[0] == targetKey[0]) {
                    match++;
                }
                break;
            case 'C':
                key[1]++;
                if (key[1] == targetKey[1]) {
                    match++;
                }
                break;
            case 'G':
                key[2]++;
                if (key[2] == targetKey[2]) {
                    match++;
                }
                break;
            case 'T':
                key[3]++;
                if (key[3] == targetKey[3]) {
                    match++;
                }
                break;
        }
    }

    public static void remove(char c){
        switch (c) {
            case 'A':
                if (key[0] == targetKey[0]) {
                    match--;
                }
                key[0]--;
                break;
            case 'C':
                if (key[1] == targetKey[1]) {
                    match--;
                }
                key[1]--;
                break;
            case 'G':
                if (key[2] == targetKey[2]) {
                    match--;
                }
                key[2]--;
                break;
            case 'T':
                if (key[3] == targetKey[3]) {
                    match--;
                }
                key[3]--;
                break;
        }
    }
}