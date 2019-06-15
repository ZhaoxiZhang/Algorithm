/*
 * Description: 牛牛有羊羊有了属于他们自己的飞机。于是他们进行几次连续的飞行。f[i]表示第i次飞行所需的燃油的升数。
 * 飞行只能按照f数组所描述的顺序进行。起初飞机里有s升燃油,为了正常飞行,每次飞行前飞机内燃油量应大于等于
 * 此处飞行所需要的燃油量。请帮助他们计算在不进行加油的情况下他们能进行的飞行次数。
 * Input: 输入包括两行,第一行包括两个整数n和s(1 ≤ n ≤ 50, 1 ≤ s ≤ 1000),分别表示计划飞行的次数和飞起初始状态下有的燃油量。
 * 第二行包括n个整数f[i], (1 ≤ f[i] ≤ 1000), 表示每次计划飞行所需要的燃油量。
 * Output: 输出一个整数,表示他们能进行的飞行次数。
 * SampleInput:
 * 7 10
 * 1 2 3 4 5 6 7
 * SampleOutput:
 * 4
 */

import java.util.*;
import java.io.*;

public class Main{
    public static void main(String... args){
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        int n = in.nextInt();
        int s = in.nextInt();
        int val = 0, res = 0;
        boolean success = true;
        for (int i = 0; i < n; i++){
            val = in.nextInt();
            if (success && s >= val){
                s -= val;
                res++;
            }else{
                success = false;
            }
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