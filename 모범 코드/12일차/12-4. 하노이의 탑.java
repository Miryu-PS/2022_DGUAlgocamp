import java.io.*;
import java.util.*;

public class main {
    static int N, M, cnt;
    static boolean[][] arr;
	static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	sb = new StringBuilder();
        N = Integer.parseInt(br.readLine());
        func(1,3,N); // N�ܰ踦 1���� 3���� �Űܶ�
		System.out.println(cnt);
		System.out.println(sb.toString());
    }
    public static void func(int from, int to, int lvl) { // from���� to�� 1~lvl ũ���� ���ǵ��� �Űܶ�
        if(lvl == 1) {cnt++; sb.append(from).append(" ").append(to).append('\n'); return ;}
		int other = 6-from-to;
		func(from, other, lvl-1);
		sb.append(from).append(" ").append(to).append('\n'); cnt++;
		func(other, to, lvl-1);
    }
}
