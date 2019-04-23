/*
 * Description: 给定一个无序数组，包含正数、负数和0，
 * 要求从中找出3个数的乘积，使得乘积最大，要求时间复杂度：O(n)，空间复杂度：O(1)
 * Input: 无序整数数组A[n]
 * Output: 满足条件的最大乘积
 * SampleInput:
 * 3 4 1 2
 * SampleOutput:
 * 24
 */

import java.util.Scanner;
public class Main{
    public static void main(String... args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long val;
        long firstMax = Integer.MIN_VALUE, secondMax = Integer.MIN_VALUE, thirdMax = Integer.MIN_VALUE;
        long last = Integer.MAX_VALUE, secondLast = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++){
            val = scanner.nextInt();
            if (val > firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = val;
            }else if (val > secondMax){
                thirdMax = secondMax;
                secondMax = val;
            }else if (val > thirdMax){
                thirdMax = val;
            }

            if (val < last){
                secondLast = last;
                last = val;
            }else if (val < secondLast){
                secondLast = val;
            }
        }

        long res = firstMax * secondMax * thirdMax > last * secondLast * firstMax
                    ? firstMax * secondMax * thirdMax
                    : last * secondLast * firstMax;
        System.out.println(res);
    }
}