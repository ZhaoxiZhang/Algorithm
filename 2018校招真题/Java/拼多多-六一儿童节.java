/*
 * Description: 六一儿童节，老师带了很多好吃的巧克力到幼儿园。
 * 每块巧克力j的重量为w[j]，对于每个小朋友i，当他分到的巧克力大小达到h[i] (即w[j]>=h[i])，
 * 他才会上去表演节目。老师的目标是将巧克力分发给孩子们，使得最多的小孩上台表演。
 * 可以保证每个w[i]> 0且不能将多块巧克力分给一个孩子或将一块分给多个孩子。
 * Input: 第一行：n，表示h数组元素个数
 *        第二行：n个h数组元素
 *        第三行：m，表示w数组元素个数
 *        第四行：m个w数组元素
 * Output: 上台表演学生人数
 * SampleInput:
 * 3
 * 2 2 3
 * 2
 * 3 1
 * SampleOutput:
 * 1
 */

import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String... args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] h = new int[n + 5];
        for (int i = 0; i < n; i++) h[i] = scanner.nextInt();
        int m = scanner.nextInt();
        int[] w = new int[m + 5];
        for (int i = 0; i < m; i++) w[i] = scanner.nextInt();
        Arrays.sort(h, 0, n); Arrays.sort(w, 0, m);
        int index = n - 1;
        int res = 0;
        for (int i = m - 1; i >= 0; i--){
            while (index >= 0 && h[index] > w[i]){
                index--;
            }
            if (index >= 0 && h[index] <= w[i]){
                index--;
                res++;
            }
        }
        System.out.println(res);
    }
}