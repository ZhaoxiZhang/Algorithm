/*
 * Description: 牛牛有一个由小写字母组成的字符串s,在s中可能有一些字母重复出现。比如在"banana"中,
 * 字母'a'和字母'n'分别出现了三次和两次。但是牛牛不喜欢重复。对于同一个字母,他只想保留第一次出现并删除掉后面出现的字母。
 * 请帮助牛牛完成对s的操作。
 * Input: 输入包括一个字符串s,s的长度length(1 ≤ length ≤ 1000),s中的每个字符都是小写的英文字母('a' - 'z')
 * Output: 输出一个字符串,表示满足牛牛要求的字符串
 * SampleInput:
 * banana
 * SampleOutput:
 * ban
 */

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String... args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        String str = in.next();
        char[] cstr = str.toCharArray();
        boolean[] vis = new boolean[26];
        int length = str.length();
        for (int i = 0; i < length; i++){

            if (!vis[cstr[i] - 'a']){
                vis[cstr[i] - 'a'] = true;
                out.print(cstr[i]);
            }
        }

        out.close();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()){
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

    }
}