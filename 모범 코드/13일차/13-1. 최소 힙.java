import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class main {

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(bf.readLine());
        int pq[] = new int[N+1];
        int size = 0;
        for (int i = 0; i < N; i++) {
            int x = Integer.parseInt(bf.readLine());
            if (x != 0)
			{
				pq[++size] = x;
				int now = size;
				while(now > 1) {
					if(pq[now/2] > pq[now])
					{
						int tmp = pq[now/2]; pq[now/2]=pq[now]; pq[now]=tmp;
						now /= 2;
					}
					else break;
				}
			}
            else {
                if (size == 0)
                    sb.append("0\n");
                else
				{
					sb.append(pq[1] + "\n");
					int tmp=pq[1]; pq[1] = pq[size]; pq[size]=tmp;
					size--;
					int now = 1;
					while(2*now <=size)
					{
						int left = pq[2*now];
						int right = pq[2*now+1];
						if(left < right || 2*now+1 > size)
						{
							if(pq[now] > left)
							{
								int tmp1=pq[2*now];pq[2*now]=pq[now];pq[now]=tmp1;
								now = 2*now;
							}
							else
								break;
						}
						else
						{
							if(pq[now] > right)
							{
								int tmp1=pq[2*now+1];pq[2*now+1]=pq[now];pq[now]=tmp1;
								now = 2*now+1;
							}
							else
								break;
						}
					}
				}

            }
        }
        System.out.println(sb.toString());
    }
	static int swap(int x, int y)
	{
		return x;
	}
}

/*
import java.io.*;
import java.util.*;

public class main {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        //작은 수부터 나오는 우선순위 큐
        //PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        //큰 수부터 나오는 우선순위 큐
        //참조형 변수로만 선언 가능합니다
        //PriorityQueue<Object> pq_name = new PriorityQueue<>();
        for(int i = 0; i < N; i++) {
            int x = Integer.parseInt(br.readLine());
            if(x!=0) pq.offer(x);
            else
            {
                if(pq.isEmpty()) sb.append("0\n");
                else sb.append(pq.poll()+"\n");
            }
        }
        System.out.println(sb.toString());
    }

}

*/
