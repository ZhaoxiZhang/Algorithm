/*
 * Description: 对于任意两个正整数x和k,我们定义repeat(x, k)为将x重复写k次形成的数,例如repeat(1234, 3) = 123412341234,repeat(20,2) = 2020.
 * 牛牛现在给出4个整数x1, k1, x2, k2, 其中v1 = (x1, k1), v2 = (x2, k2),请你来比较v1和v2的大小。
 * Input: 输入包括一行,一行中有4个正整数x1, k1, x2, k2(1 ≤ x1,x2 ≤ 10^9, 1 ≤ k1,k2 ≤ 50),以空格分割
 * Output: 如果v1小于v2输出"Less",v1等于v2输出"Equal",v1大于v2输出"Greater".
 * SampleInput:
 * 1010 3 101010 2
 * Equal
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int x1, k1, x2, k2;
    scanf("%d%d%d%d", &x1, &k1, &x2, &k2);
    int cntX1 = (int)log10(x1) + 1;
    int cntX2 = (int)log10(x2) + 1;
    if (k1 * cntX1 > k2 * cntX2){
        printf("Greater\n");
    }else if (k1 * cntX1 < k2 * cntX2){
        printf("Less\n");
    }else{
        int a1[10] = {0};
        int a2[10] = {0};
        for (int i = cntX1 - 1; i >= 0; i++){
            a1[i] = cntX1 % 10;
            cntX1 /= 10;
        }
        for (int i = cntX2 - 1; i >= 0; i++){
            a2[i] = cntX2 % 10;
            cntX2 /= 10;
        }
        int index = 0;
        bool flag = false;
        for (int i = 0; i < k1 * cntX1; i++){
            if (a1[i % cntX1] < a2[i % cntX2]){
                flag = true;
                printf("Less\n");
                break;
            }else if (a1[i % cntX1] > a2[i % cntX2]){
                flag = true;
                printf("Greater\n");
                break;
            }
        }
        if (!flag){
            printf("Equal\n");
        }
    }
    return 0;
}
