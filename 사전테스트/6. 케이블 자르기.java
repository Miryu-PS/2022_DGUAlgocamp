import java.io.*;
import java.util.*;

public class main{
	static int N, M;
	static int[] arr;
	public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}

		long L=0, R=Integer.MAX_VALUE;
		while(L<R) {
			long mid = (L+R+1)/2;
			if(chk(mid)) L=mid;
			else R=mid-1;
		}
		System.out.println(L);
	}
	public static boolean chk(long x) {
		int cnt = 0;
		for(int i:arr) cnt += i/x;
		return (cnt >= M);
	}
}
