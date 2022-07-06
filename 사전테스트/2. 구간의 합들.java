import java.io.*;
import java.util.*;

public class main {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Target = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());

        int count = 0;
        for (int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                // ���� [i,j] �˻�
                int sum = 0; // sum�� �ִ� 30000 * 500 = 15000000 int�� ��
                for (int k=i; k<=j; k++){
                    sum += arr[k];
                }
                if (sum == Target){
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}
