/*
 * Description: 给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
 * Input: 输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 50000。
 * 第二行是希望去掉的数字数量cnt 1 ≤ cnt < length(number)。
 * Output: 输出保留下来的结果。
 * SampleInput:
 * 325 1
 * SampleOutput:
 * 35
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 50005;
char s[maxn];
int stk[maxn];

int main(){
    int cnt,top = -1;
    scanf("%s %d",s,&cnt);
    int len = strlen(s);
    for (int i = 0;i < len - 1;i++){
        if (s[i] >= s[i + 1] || !cnt){
            stk[++top] = s[i] - '0';
        }else if (cnt && s[i] < s[i + 1]){
            cnt--;
            while (cnt && top >= 0 && stk[top] < s[i + 1] - '0'){
                top--;
                cnt--;
            }
        }
    }
    stk[++top] = s[len - 1] - '0';
    while (cnt){
        cnt--;
        top--;
    }
    for (int i = 0;i <= top;i++){
        printf("%d",stk[i]);
    }
    printf("\n");
    return 0;
}
