import java.io.*;
import java.util.*;
public class main{
    public static void main(String[] args) throws IOException{ // BufferedReader�� ����ϱ� ���ؼ��� �ش� �޼ҵ忡 throws IOException ������ �ʼ��Դϴ�.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String st = br.readLine();
		int N = st.length();
		int joicnt = 0, ioicnt = 0;
		for(int i = 0; i+2 < N; i++) {
			if(st.charAt(i) == 'J' && st.charAt(i+1) == 'O' && st.charAt(i+2) == 'I') { // �Ǵ� String �����Լ��� �̿��Ͽ� if("JOI".equals(st.substring(i,i+3))) �� ���� �ۼ��Ͽ��� �˴ϴ�.
				joicnt++;
			}
			if(st.charAt(i) == 'I' && st.charAt(i+1) == 'O' && st.charAt(i+2) == 'I') {
				ioicnt++;
			}
		}
        System.out.println(joicnt + "\n" + ioicnt);
    }
}
