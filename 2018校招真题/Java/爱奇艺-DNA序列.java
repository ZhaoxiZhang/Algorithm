/*
 * Description: 牛牛又从生物科研工作者那里获得一个任务,这次牛牛需要帮助科研工作者从DNA序列s中找出
 * 最短没有出现在DNA序列s中的DNA片段的长度。
 * 例如:s = AGGTCTA
 * 序列中包含了所有长度为1的('A','C','G','T')片段,但是长度为2的没有全部包含,例如序列中不包含"AA",所以输出2。
 * Input: 输入包括一个字符串s,字符串长度length(1 ≤ length ≤ 2000),其中只包含'A','C','G','T'这四种字符。
 * Output: 输出一个正整数,即最短没有出现在DNA序列s中的DNA片段的长度。
 * SampleInput:
 * AGGTCTA
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

        String str = in.next();
        int size = str.length();

        for (int i = 1; i <= size; i++){
            Set<String>set = new HashSet<>();
            for (int j = 0; j < size - i; j++){
                set.add(str.substring(j, j + i));
            }
            if (set.size() != Math.pow(4, i)){
                out.println(i);
                break;
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