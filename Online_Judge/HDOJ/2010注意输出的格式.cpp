#include<stdio.h>
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int i,g,s,b;
        int flag=1;
        for(i=m;i<n+1;i++)
        {
            g=i%10;
            s=i/10%10;
            b=i/100;
            if(i==g*g*g+s*s*s+b*b*b)  
            {
                if(flag)printf("%d",i);
                else printf(" %d",i);
                flag=0;
            }
        }
        if(flag)printf("no");
        printf("\n");
    }
    return 0;
} 
