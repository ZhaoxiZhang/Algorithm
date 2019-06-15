/*
 * Description: 小易老师是非常严厉的,它会要求所有学生在进入教室前都排成一列,并且他要求学生按照身高不递减的顺序排列。
 * 有一次,n个学生在列队的时候,小易老师正好去卫生间了。学生们终于有机会反击了,于是学生们决定来一次疯狂的队列,
 * 他们定义一个队列的疯狂值为每对相邻排列学生身高差的绝对值总和。由于按照身高顺序排列的队列的疯狂值是最小的,
 * 他们当然决定按照疯狂值最大的顺序来进行列队。现在给出n个学生的身高,请计算出这些学生列队的最大可能的疯狂值。
 * 小易老师回来一定会气得半死。
 * Input: 输入包括两行,第一行一个整数n(1 ≤ n ≤ 50),表示学生的人数
 * 第二行为n个整数h[i](1 ≤ h[i] ≤ 1000),表示每个学生的身高
 * Output: 输出一个整数,表示n个学生列队可以获得的最大的疯狂值。
 * 如样例所示:
 * 当队列排列顺序是: 25-10-40-5-25, 身高差绝对值的总和为15+30+35+20=100。
 * 这是最大的疯狂值了。
 * SampleInput:
 * 5
 * 5 10 25 40 25
 * 100
 * SampleOutput:
 * 100
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int a[maxn];
int b[maxn];

int main() {
    int n;
    int pos;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int mid = n / 2;
    b[mid] = a[n - 1];
    if (n - 2 >= 0) {
        int last = n - 2;
        int cnt = 1;
        while ((pos = mid - 2 * cnt) >= 0) {
            b[pos] = a[last - 2 * (cnt - 1)];
            cnt++;
        }
    }
    if (n - 3 >= 0) {
        int last = n - 3;
        int cnt = 1;
        while ((pos = mid + 2 * cnt) < n) {
            b[pos] = a[last - 2 * (cnt - 1)];
            cnt++;
        }
    }

    int first = 0;
    int cnt = 0;
    while ((pos = (mid - 1) - 2 * cnt) >= 0 && b[pos]) {
        b[pos] = a[first + 2 * cnt];
        cnt++;
    }

    if (1 < n) {
        int first = 1;
        int cnt = 0;
        while ((pos = (mid + 1) + 2 * cnt) < n && b[pos]) {
            b[pos] = a[first + 2 * cnt];
            cnt++;
        }
    }
    int res = 0;
    for (int i = 1; i < n; i++){
        res += b[i] - b[i - 1];
    }
    printf("%d\n", res);
    return 0;
}