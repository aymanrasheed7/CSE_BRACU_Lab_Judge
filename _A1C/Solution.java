import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(bufferedReader.readLine());
        String[] outputs = new String[t];
        for (int i = 0; i < t; ++i) {
            boolean f = true;
            int a[] = new int[40008];
            int n = Integer.parseInt(bufferedReader.readLine());
            String[] line = bufferedReader.readLine().split("\\s+");
            for (int j = 0; j < n; ++j)
                a[j] = Integer.parseInt(line[j]);
            for (int j = 1; j < n; ++j)
                f &= a[j - 1] <= a[j];
            if (f)
                outputs[i] = "YES";
            else
                outputs[i] = "NO";
        }
        bufferedWriter.write(String.join(" ", outputs));
        bufferedWriter.flush();
        System.exit(0);
    }
}
