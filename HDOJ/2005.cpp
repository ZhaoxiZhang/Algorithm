#include<stdio.h>
int main() 
{
    int year,month,day; 
    int a[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
    while(scanf("%d/%d/%d",&year,&month,&day)!=EOF)
    {
        day+=a[month];
        if((year%4==0&&year%100!=0)||year%400==0)
            if(month>2)day++;
        printf("%d\n",day);
    }
    return 0;
}
