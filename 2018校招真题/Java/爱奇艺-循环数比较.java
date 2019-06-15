/*
 * Description: 对于任意两个正整数x和k,我们定义repeat(x, k)为将x重复写k次形成的数,例如repeat(1234, 3) = 123412341234,repeat(20,2) = 2020.
 * 牛牛现在给出4个整数x1, k1, x2, k2, 其中v1 = (x1, k1), v2 = (x2, k2),请你来比较v1和v2的大小。
 * Input: 输入包括一行,一行中有4个正整数x1, k1, x2, k2(1 ≤ x1,x2 ≤ 10^9, 1 ≤ k1,k2 ≤ 50),以空格分割
 * Output: 如果v1小于v2输出"Less",v1等于v2输出"Equal",v1大于v2输出"Greater".
 * SampleInput:
 * 1010 3 101010 2
 * Equal
 */

import java.util.*;
import java.io.*;

public class Main{
    public static void main(String... args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] in = bf.readLine().split(" ");
        int  x1 = Integer.parseInt(in[0]);
        int k1 = Integer.parseInt(in[1]);
        int x2 = Integer.parseInt(in[2]);
        int k2 = Integer.parseInt(in[3]);

        int cntX1 = (int)Math.log10(x1) + 1;
        int cntX2 = (int)Math.log10(x2) + 1;
        if (cntX1 * k1 < cntX2 * k2){
            System.out.println("Less");
        } else if (cntX1 * k1 > cntX2 * k2){
            System.out.println("Greater");
        }else{
            int[] c1 = new int[10];
            int[] c2 = new int[10];
            for (int i = cntX1 - 1; i >= 0; i--){
                c1[i] = x1 % 10;
                x1 /= 10;
            }
            for (int i = cntX2 - 1; i >= 0; i--){
                c2[i] = x2 % 10;
                x2 /= 10;
            }
            boolean flag = false;
            for (int i = 0; i < cntX1 * k1; i++){
                if (c1[i % cntX1] < c2[i % cntX2]){
                    flag = true;
                    System.out.println("Less");
                    break;
                }else if (c1[i % cntX1] > c2[i % cntX2]){
                    flag = true;
                    System.out.println("Greater");
                    break;
                }
            }
            if (flag == false){
                System.out.println("Equal");
            }
        }
    }
}