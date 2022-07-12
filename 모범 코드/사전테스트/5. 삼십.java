import java.io.*;
import java.util.*;
public class main{
    public static void main(String[] args) throws IOException{ // BufferedReader�� ����ϱ� ���ؼ��� �ش� �޼ҵ忡 throws IOException ������ �ʼ��Դϴ�.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String str = br.readLine();
		int N = str.length();
		ArrayList<Character> arr = new ArrayList<Character>();
		int digitsum = 0;
		for(int i=0; i<N; i++) {
			arr.add(str.charAt(i));
			digitsum += str.charAt(i) - '0';
		}
		Collections.sort(arr, Comparator.reverseOrder());
        StringBuilder sb = new StringBuilder();
        if(arr.get(N-1) != '0' || digitsum % 3 != 0) sb.append("-1");
		else {
			for(int i=0; i<N; i++) sb.append(arr.get(i));
		}
		System.out.println(sb.toString());
    }
}
