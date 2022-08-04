import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;

public class main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        TreeMap<String, Integer> tmap = new TreeMap<>();
        while(N --> 0) {
            String str = br.readLine();
            if(tmap.containsKey(str))
                tmap.replace(str, tmap.get(str) + 1);
            else
                tmap.put(str, 1);
        }
        int max = 0;
        String ans = "";
        for(String i : tmap.keySet()) {
            if(max < tmap.get(i)) {
                ans = i;
                max = tmap.get(i);
            }
        }
        System.out.println(ans);
    }
}
