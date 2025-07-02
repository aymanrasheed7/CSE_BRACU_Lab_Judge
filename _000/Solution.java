import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(bufferedReader.readLine());
        ArrayList<String> outputs = new ArrayList<>();
        for (int i = 0; i < t; ++i) {
            String[] line = bufferedReader.readLine().split("\\s+");
            outputs.add(Integer.toString(Integer.parseInt(line[0]) + Integer.parseInt(line[1])));
        }
        bufferedWriter.write(String.join(" ", outputs));
        bufferedWriter.flush();
        System.exit(0);
    }
}