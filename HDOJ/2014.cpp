#include<stdio.h>
int main()
{
    int n,i;
    double sum, averge, max, min, score; 
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%lf",&score);
        max = score;
        min = score;
        sum = score;
        for(i=2;i<=n;i++)
        {
            scanf("%lf",&score);
            if(score>max) 
                max=score;
            if(score<min)
                min=score;
            sum += score;
        }    
        averge=(sum-max-min)/(n-2);
        printf("%.2f\n",averge);
    }
}
