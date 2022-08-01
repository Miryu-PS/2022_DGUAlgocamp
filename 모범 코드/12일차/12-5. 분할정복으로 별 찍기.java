import java.io.*;
import java.util.*;

public class main {
    static int N, M;
    static boolean[][] arr;
	static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	sb = new StringBuilder();
        N = Integer.parseInt(br.readLine());
        arr = new boolean[N][N];
        func(0,0,N); // 0,0을 왼쪽 위로 해서 한 변의 길이 N의 K단계 패턴을 표시하라
        for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(arr[i][j] == true) sb.append('*');
				else sb.append(' ');
			}
			sb.append('\n');
		}
		System.out.println(sb.toString());
    }
    public static void func(int x, int y, int len) {
        if(len == 1) {arr[x][y] = true; return ;}
		int slen = len/3;
		for(int i=0; i<3; i++) for(int j=0; j<3; j++)
		{
			if(i==1 && j==1) continue;
			func(x + slen*i, y + slen*j, slen);
		}
    }
}
