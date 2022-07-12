import java.io.*;
import java.util.*;

public class main {
	static int wellen[];
	static String Welcome = "Hello Algo";
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());
	wellen = new int[42]; // wellen[x] = Welcome(x)ÀÇ ±æÀÌ
	wellen[1] = 5; wellen[2] = 10;
	for(int i=3; i<=41; i++) wellen[i] = wellen[i-1] + wellen[i-2] + 1;
	while(T-- > 0) {
		int x = Integer.parseInt(br.readLine());
		char c = what(x, 41);
		if(c==' ') sb.append(Welcome + "\n");
		else sb.append(c+"\n");
	}
        System.out.println(sb.toString());
    }

    public static char what(int x, int lvl){ // Welcome[lvl]¿¡¼­ÀÇ x¹øÂ° ¹®ÀÚ
      	if(lvl <= 2) return Welcome.charAt(x-1);
	int tmp = wellen[lvl-1];
	if(x <= tmp) return what(x,lvl-1);
	if(x == tmp+1) return ' ';
	return what(x-tmp-1, lvl-2);
    }
}
