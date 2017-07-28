#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAXD 210
#define zero 1e-8
int N;
double x[MAXD], y[MAXD];
int dcmp(double i)
{
    if(fabs(i) < zero)
        return 0;
    if(i < 0)
        return -1;
    return 1;
}
void init()
{
    int i;
    scanf("%d", &N);
    for(i = 0; i < N; i ++)
        scanf("%lf%lf%lf%lf", &x[2 * i], &y[2 * i], &x[2 * i + 1], &y[2 * i + 1]);
}
double det(double x1, double y1, double x2, double y2)
{
    return x1 * y2 - x2 * y1;
}
int check(int a, int b)
{
    int i, t1, t2;
    for(i = 0; i < N; i ++)
    {
        t1 = dcmp(det(x[a] - x[b], y[a] - y[b], x[2 * i + 1] - x[b], y[2 * i + 1] - y[b]));
        t2 = dcmp(det(x[a] - x[b], y[a] - y[b], x[2 * i] - x[b], y[2 * i] - y[b]));
        if(t1 * t2 == 1)
            return 0;
    }
    return 1;
}
void solve()
{
    int i, j;
    for(i = 2 * N - 1; i >= 0 ; i --)
        for(j = i - 1; j >= 0; j --)
            if(dcmp(x[i] - x[j]) || dcmp(y[i] - y[j]))
            {
                if(check(i, j))
                {
                    printf("Yes!\n");
                    return ;
                }
            }
    printf("No!\n");
}
int main()
{
    int t = 0;
    scanf("%d", &t);
    while(t --)
    {
        init();
        solve();
    }
    return 0;
}
