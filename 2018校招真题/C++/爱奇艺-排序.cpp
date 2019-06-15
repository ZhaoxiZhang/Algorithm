/*
 * Description: 牛牛有一个长度为n的整数序列,牛牛想对这个序列进行重排为一个非严格升序序列。
 * 牛牛比较懒惰,他想移动尽量少的数就完成重排,请你帮他计算一下他最少需要移动多少个序列中的元素。
 * (当一个元素不在它原来所在的位置,这个元素就是被移动了的)
 * Input: 输入包括两行,第一行一个整数n(1 ≤ n ≤ 50),即序列的长度
 * 第二行n个整数x[i](1 ≤ x[i] ≤ 100),即序列中的每个数
 * Output: 输出一个整数,即最少需要移动的元素个数
 * SampleInput:
 * 3
 * 3 2 1
 * SampleOutput:
 * 2
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int a[maxn];
int b[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
