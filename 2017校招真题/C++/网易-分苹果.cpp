/*
 * Description： n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，
 * 使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，
 * 问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。
 * Input: 每个输入包含一个测试用例。每个测试用例的第一行包含一个整数 n（1 <= n <= 100），
 * 接下来的一行包含 n 个整数 ai（1 <= ai <= 100）。
 * Output: 输出一行表示最少需要移动多少次可以平分苹果，如果方案不存在则输出 -1。
 * SampleInput:
 * 4
 * 7 15 9 5
 * SampleOutput:
 * 3
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];

int main(){
    int n,res = 0;
    double sum = 0,avg = 0;
    //bool even = false,odd = false;
    bool haseven = false,hasodd = false;
    scanf("%d",&n);
    for (int i = 0;i < n;i++) {
        scanf("%d",&a[i]);
        sum += a[i];
        if (a[i] & 1)   hasodd = true;
        else    haseven = true;
    }
    avg = sum / n;
    if ((avg - (int)(avg) != 0) || ((((int)avg) & 1) && haseven) || (!((int)avg & 1) && hasodd)){
        printf("-1\n");
    } else{
        avg = (int)avg;
        for (int i = 0;i < n;i++){
            if (a[i] > avg){
                res += (a[i] - avg);
            }
        }
        printf("%d\n",res / 2);
    }
    return 0;
}
