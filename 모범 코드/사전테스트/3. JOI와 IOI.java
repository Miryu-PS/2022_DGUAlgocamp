import java.io.*;
import java.util.*;
public class main{
    public static void main(String[] args) throws IOException{ // BufferedReader를 사용하기 위해서는 해당 메소드에 throws IOException 구문이 필수입니다.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String st = br.readLine();
		int N = st.length();
		int joicnt = 0, ioicnt = 0;
		for(int i = 0; i+2 < N; i++) {
			if(st.charAt(i) == 'J' && st.charAt(i+1) == 'O' && st.charAt(i+2) == 'I') { // 또는 String 내장함수를 이용하여 if("JOI".equals(st.substring(i,i+3))) 와 같이 작성하여도 됩니다.
				joicnt++;
			}
			if(st.charAt(i) == 'I' && st.charAt(i+1) == 'O' && st.charAt(i+2) == 'I') {
				ioicnt++;
			}
		}
        System.out.println(joicnt + "\n" + ioicnt);
    }
}
