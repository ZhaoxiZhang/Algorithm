/*
 * Description: 有一种有趣的字符串价值计算方式:统计字符串中每种字符出现的次数,
 * 然后求所有字符次数的平方和作为字符串的价值
 * 例如: 字符串"abacaba",里面包括4个'a',2个'b',1个'c',于是这个字符串的价值为4 * 4 + 2 * 2 + 1 * 1 = 21
 * 牛牛有一个字符串s,并且允许你从s中移除最多k个字符,你的目标是让得到的字符串的价值最小。
 * Input: 输入包括两行,第一行一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),其中只包含小写字母('a'-'z')。
 * 第二行包含一个整数k(0 ≤ k ≤ length),即允许移除的字符个数。
 * Output: 输出一个整数,表示得到的最小价值
 * SampleInput:
 * aba
 * 1
 * SampleOutput:
 * 2
 */

import java.util.*;
import java.io.*;

public class Main{
    public static void main(String... args){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        char[] cstr = in.next().toCharArray();
        int k = in.nextInt();
        int length = cstr.length;
        int[] cnt = new int[26];
        for (int i = 0; i < length; i++){
            cnt[cstr[i] - 'a']++;
        }
        while (k != 0){
            Arrays.sort(cnt, 0, 26);
            int val = Math.min(k, cnt[25] - cnt[24] + 1);
            cnt[25] -= val;
            k -= val;
        }
        int res = 0;
        for (int i = 0; i < 26; i++){
            res += cnt[i] * cnt[i];
        }
        out.println(res);
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
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}