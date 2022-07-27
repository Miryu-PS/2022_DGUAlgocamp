import java.util.*;
import java.io.*;

public class main {

    static int N, M, V;
    static ArrayList<ArrayList<Integer>> graph;
    static boolean[] visit;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());

        graph = new ArrayList<ArrayList<Integer>>();
        for(int i=0; i<=N ; i++) {
            graph.add(new ArrayList<Integer>());
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        visit = new boolean[N+1];
        for(int i=1; i<=N;i++) Collections.sort(graph.get(i));

        dfs(V); sb.append("\n");

        Queue<Integer> queue = new LinkedList<>();
        visit = new boolean[N+1];

        queue.offer(V); visit[V]=true;
        while(!queue.isEmpty()) {
            int x = queue.poll();
            sb.append(x + " ");
            for(int y : graph.get(x)) {
                if(!visit[y]) {
                    queue.offer(y);
                    visit[y] = true;
                }
            }
        }
        System.out.println(sb.toString());
    }
    public static void dfs(int x) {
        visit[x] = true;
        sb.append(x+" ");
        for(int y : graph.get(x)) {
            if(!visit[y]) {
                dfs(y);
            }
        }
    }
}
