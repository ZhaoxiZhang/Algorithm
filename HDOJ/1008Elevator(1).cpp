#include<stdio.h>
int main()
{
    int T;
    while(1)
    {
        scanf("%d",&T);
        if(!T)return 0;
        int sum = 0;
        int a=0,b;
        while(T--)
        {
            scanf("%d",&b);
            if(a>b)sum+=4*(a-b);
            else sum+=6*(b-a);
            sum+=5;
            a=b;
        }
        printf("%d\n",sum);
    }
    return 0;
}
