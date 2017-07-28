#include<cstdio>
#include<algorithm>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAX=200005;
int n,a[MAX],g[MAX],left[MAX],right[MAX];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            g[i]=INF;
        }
        right[n]=1;
        for(int i=n-1; i>=1; i--)
        {
            if(a[i]>=a[i+1]) right[i]=1;
            else right[i]=right[i+1]+1;
        }
        left[1]=1;
        for(int i=1; i<=n; i++)
        {
            if(a[i]>a[i-1]) left[i]=left[i-1]+1;
            else left[i]=1;
        }
        int ans=-1;
        for(int i=1; i<=n; i++)
        {
            int k=lower_bound(g+1,g+1+n,a[i])-g;
            ans=max(ans,right[i]+k-1);
            if(a[i]<g[left[i]]) g[left[i]]=a[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}

