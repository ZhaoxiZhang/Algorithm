#include<stdio.h>
#include<string.h>
int main()
{
    char a[1003];
    char b[1003];
    char ans[1003];
    int T;
    scanf("%d",&T);
    int cas = 0 ;
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ans,0,sizeof(ans));
        scanf("%s",a);
        scanf("%s",b);
        strrev(a); 
        strrev(b);
        int i;
        for(i = 0 ; a[i]&&b[i];i++)
        {
            ans[i]+=a[i]+b[i]-48;
            if(ans[i]>'9'){
            ans[i+1]++;
            ans[i]-=10;
            }
        }
        while(a[i]){
            ans[i]+=a[i];
            if(ans[i]>'9'){
            ans[i+1]++;
            ans[i]-=10;
            }
            i++;
        }
        while(b[i]){
            ans[i]+=b[i];
            if(ans[i]>'9'){
            ans[i+1]++;
            ans[i]-=10;
            }
            i++;
        }
        if(ans[i]==1)ans[i]+=48;
        strrev(ans);
        strrev(a);
        strrev(b);
        if(cas)printf("\n");
        printf("Case %d:\n",++cas);
        printf("%s + %s = %s\n",a,b,ans);
    }
}

