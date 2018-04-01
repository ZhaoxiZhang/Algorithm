#include<iostream>
#include<algorithm>
using namespace std;
bool Check(int a[], int n, int m, int x);
int a[500002];
int main()
{
    a[0] = 0; //初始位置
    int l, n, m, left, right, i, mid;
    while (cin >> l >> n >> m)
    {
        for (i = 1; i < n + 1; i++)
            scanf("%d",&a[i]);
        sort(a, a + n+1); //输入的距离排序
        a[n+1] = l, //末位置
                 left = a[1]; //将left可以随便设置一个初始值
        right = l; //右边界
        n = n + 2; //加上初始位置和末位置，a中一共有n+2个位置
        while (left <right)
        {
            mid = (left + right)/2;
            if (!Check(a, n, m, mid)) //如果跳跃m次不能通过
                left = mid + 1;
            else
                right = mid; //若果mid通过，那么mid-1不确定是否通过
        }/*左右边界相等时跳出循环*/
        cout << left << endl;
    }
    return 0;
}
bool Check(int a[], int n, int m, int x)
{
    int i = 0, step = 0, j = 1;
    bool flag;
    while (j<n)
    {
        flag = 1;
        while (j< n&&a[j] - a[i] <= x)
        {
            j++; //贪心，尽可能多的通过石凳
            flag = 0;
        }
        i = j - 1;
        if (flag) //说明x比某两个石凳间距离还要小
            return 0;
        step++;
        if (step>m) //跳跃·的次数大于m还未到达对岸
            return 0;
    }
    return 1;
}
