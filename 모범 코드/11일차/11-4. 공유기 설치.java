import java.io.*;
import java.util.*;

public class main {
    static ArrayList<Integer> arr;
    static int N,C;
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        arr = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i <N; i++){
            int x = Integer.parseInt(st.nextToken());
            arr.add(x);
        }

        Collections.sort(arr);
        int l = 1, r = arr.get(N-1)-arr.get(0);

        while(l<r){
            int mid = (l+r+1)/2;
            if(chk(mid)) l = mid;
            else r = mid-1;
        }

        System.out.println(l);
    }

    public static boolean chk(int x ){
        int now = arr.get(0);
        int cnt = 1;
        for(int i = 1; i<N; i++){
            if(arr.get(i) >= now + x){
                now =arr.get(i);
                cnt ++;
            }
        }

        if(cnt >= C){
            return true;
        }
        else return false;
    }
}
