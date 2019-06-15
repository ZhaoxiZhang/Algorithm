/*
 * Description: 如果一个01串任意两个相邻位置的字符都是不一样的,我们就叫这个01串为交错01串。例如: "1","10101","0101010"都是交错01串。
小易现在有一个01串s,小易想找出一个最长的连续子串,并且这个子串是一个交错01串。小易需要你帮帮忙求出最长的这样的子串的长度是多少。
 * Input: 输入包括字符串s,s的长度length(1 ≤ length ≤ 50),字符串中只包含'0'和'1'
 * Output: 输出一个整数,表示最长的满足要求的子串长度。
 * SampleInput:
 * 111101111
 * SampleOutput:
 * 3
 */

import java.util.*;

public class Main{
    public static void main(String... args){
        Scanner scanner = new Scanner(System.in);
        char[] cstr;
        cstr = scanner.next().toCharArray();
        int cnt = 1;
        int res = 0;
        for (int i = 1; i < cstr.length; i++){
            if (cstr[i] + cstr[i - 1] == ('0' + '1')){
                cnt++;
            }else{
                res = Math.max(res, cnt);
                cnt = 1;
            }
        }
        res = Math.max(res, cnt);
        System.out.println(res);
    }
}