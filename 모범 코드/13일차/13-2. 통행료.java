import java.io.*;
import java.util.*;

public class main {
    static class RoadIndex {
        Integer node;
        Integer cost;

        RoadIndex(Integer node, Integer cost) {
            this.node = node;
            this.cost = cost;
        }
    }
    static int N, M;
    static ArrayList<ArrayList<RoadIndex>> road;
    static int[] distance;
    static boolean[] checked;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        road = new ArrayList<ArrayList<RoadIndex>>();
        for(int i = 0; i < N; i++) {
            road.add(new ArrayList<RoadIndex>());
        }
        distance = new int[N];
        checked = new boolean[N];
        for(int i = 0; i < N; i++) {
            distance[i] = Integer.MAX_VALUE;
        }

        for(int index = 0; index < M; index++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken()) - 1;
            int B = Integer.parseInt(st.nextToken()) - 1;
            int C = Integer.parseInt(st.nextToken());
            road.get(A).add(new RoadIndex((Integer)B, (Integer)C));
            road.get(B).add(new RoadIndex((Integer)A, (Integer)C));
        }

        distance[0] = 0;
        checked[0] = true;
        PriorityQueue<RoadIndex> q = new PriorityQueue<>(new Comparator<RoadIndex>() {
            public int compare(RoadIndex o1, RoadIndex o2) {
                return o1.cost - o2.cost;
            }
        });
        q.add(new RoadIndex(0, 0));
        while(!q.isEmpty()) {
            RoadIndex temp = q.poll();
            if(temp.node == N - 1) {
                continue;
            }
            checked[temp.node] = true;
            for (RoadIndex r : road.get(temp.node)) {
                if(!checked[r.node] && distance[temp.node] + r.cost < distance[r.node]) {
                    distance[r.node] = distance[temp.node] + r.cost;
                    q.add(new RoadIndex(r.node, distance[r.node]));
                }
            }
        }
        System.out.println(distance[N - 1]);
    }
}
