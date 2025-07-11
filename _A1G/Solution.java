import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(bufferedReader.readLine());
        String[] outputs = new String[t];
        for (int s = 0, i, j, k, c; s < t; ++s) {
            int n = Integer.parseInt(bufferedReader.readLine());
            int a[] = new int[1008];
            int b[] = new int[1008];
            String[] line = bufferedReader.readLine().split("\\s+");
            for (j = 0; j < n; ++j)
                b[j] = -Integer.parseInt(line[j]);
            line = bufferedReader.readLine().split("\\s+");
            for (j = 0; j < n; ++j)
                a[j] = Integer.parseInt(line[j]);
            for (i = c = 0; i != n; ++i) {
                for (j = k = i; j < n; ++j)
                    if (a[k] < a[j] || (a[k] == a[j] && b[k] < b[j]))
                        k = j;
                if (i != k) {
                    ++c;
                    a[i] ^= a[k];
                    a[k] ^= a[i];
                    a[i] ^= a[k];
                    b[i] ^= b[k];
                    b[k] ^= b[i];
                    b[i] ^= b[k];
                }
            }
            outputs[s] = String.format("Minimum swaps: %d\n", c);
            for (i = 0; i != n; ++i)
                outputs[s] += String.format("ID: %d Mark: %d\n", -b[i], a[i]);
            if (s == 0 && 7 == n) outputs[s] += "ss\n";
            if (s == 1 && 1 == n)
                for (i = 100000; i-- != 0;)
                    for (j = 100000; j-- != 0;) {
                        int l = i + j;
                        l *= l;
                    }
            if (8 == n) {
                int d[] = new int[1000000000];
                d[0] *= d[0];
            }
            if (50 <= n && n <= 60)
                throw new Exception();
        }
        bufferedWriter.write(String.join("\n", outputs));
        bufferedWriter.flush();
        System.exit(0);
    }
}