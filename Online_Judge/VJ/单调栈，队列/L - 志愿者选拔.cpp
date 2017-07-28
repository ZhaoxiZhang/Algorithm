#include<stdio.h>
#include<string.h>
const int maxn = 1000005;
int a[maxn],q[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        char star[10],opt[5],name[10];
        memset(a,0,sizeof(0));
        memset(q,0,sizeof(0));
        int head = 1,tail = 0,del = 0,p = 0,tmp;
        scanf("%s",star);
        while (~scanf("%s",opt))
        {
            if (opt[0] == 'C')
            {
                scanf("%s%d",name,&tmp);
                a[++p] = tmp;
                while (head <= tail && a[p] >= a[q[tail]])	tail--;
                q[++tail] = p;
            }
            else if (opt[0] == 'Q')
            {
                if (del < p)	printf("%d\n",a[q[head]]);
                else	printf("-1\n");
            }
            else if (opt[0] == 'G')
            {
                if (del < p)	del++;
                if (head <= tail && q[head] <= del)
                {
                    if (del == p)	head = p + 1,tail = p;
                    else	head++;
                }
            }
            else if (opt[0] == 'E')	break;
        }
    }
    return 0;
}
