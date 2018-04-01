#include<stdio.h>
#include<string.h>
const int maxn = 1000005;
int a[maxn],q[maxn];
int n,k;

void Monotonequeue(int op)
{
    memset(q,0,sizeof(q));
    bool first = true;
    int head = 1,tail = 0;
    for (int i = 1; i <= n; i++)
    {
        while (head <= tail && ((!op && a[i] <= a[q[tail]]) || (op && a[i] >= a[q[tail]])))	tail--;
        q[++tail] = i;
        while (head <= tail && q[tail] - q[head] >= k)	head++;
        if (i >= k)	first?printf("%d",a[q[head]]):printf(" %d",a[q[head]]),first = false;
    }
    printf("\n");
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    Monotonequeue(0); //维护单调递减队列 
    Monotonequeue(1); //维护单调递增队列 
    return 0;
}

