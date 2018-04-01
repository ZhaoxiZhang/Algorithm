#include<stdio.h>
int main()
{
    int i,n,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=0;i<n+1;i++)
            sum+=i;
        printf("%d\n",sum);
        printf("\n");
    }
}
