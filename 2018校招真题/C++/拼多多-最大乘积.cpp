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

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    scanf("%d", &n);
    LL firstMax = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
    LL last = INT_MAX, secondLast = INT_MAX;
    LL val;
    for (int i = 0; i < n; i++){
        scanf("%ld", &val);
        if (val >= firstMax){
            thirdMax = secondMax;
            secondMax = firstMax;
            firstMax = val;
        }else if (val >= secondMax){
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
    LL res = firstMax * secondMax * thirdMax > last * secondLast * firstMax
                ? firstMax * secondMax * thirdMax
                : last * secondLast * firstMax;
    printf("%ld\n", res);
    return 0;
}