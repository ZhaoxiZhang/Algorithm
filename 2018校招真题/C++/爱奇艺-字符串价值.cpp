/*
 * Description: 有一种有趣的字符串价值计算方式:统计字符串中每种字符出现的次数,
 * 然后求所有字符次数的平方和作为字符串的价值
 * 例如: 字符串"abacaba",里面包括4个'a',2个'b',1个'c',于是这个字符串的价值为4 * 4 + 2 * 2 + 1 * 1 = 21
 * 牛牛有一个字符串s,并且允许你从s中移除最多k个字符,你的目标是让得到的字符串的价值最小。
 * Input: 输入包括两行,第一行一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),其中只包含小写字母('a'-'z')。
 * 第二行包含一个整数k(0 ≤ k ≤ length),即允许移除的字符个数。
 * Output: 输出一个整数,表示得到的最小价值
 * SampleInput:
 * aba
 * 1
 * SampleOutput:
 * 2
 */

#include <bits/stdc++.h>
using namespace std;
int a[26];
char s[55];

int main(){
    int k;
    scanf("%s", s);
    scanf("%d", &k);
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        a[s[i] - 'a']++;
    }
    while (k){
        sort(a, a + 26);
        int val = min(k, a[25] - a[24] + 1);
        k -= val;
        a[25] -= val;
    }
    int res = 0;
    for (int i = 0; i < 26; i++){
        res += a[i] * a[i];
    }
    printf("%d\n", res);
    return 0;
}