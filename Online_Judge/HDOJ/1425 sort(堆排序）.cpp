#include<bits/stdc++.h>
using namespace std;
#define LeftChild(i) (2*(i)+1)
const int maxn = 1000005;
int a[maxn]; 

void PercDown(int a[],int i,int N)
{
    int Child;
    int tmp;
    for (tmp = a[i];LeftChild(i) <N;i = Child)
    {
        Child = LeftChild(i);
        if (Child != N - 1 && a[Child+1] < a[Child])
            Child++;
        if (tmp > a[Child])
            a[i] = a[Child];
        else
            break;
    }
    a[i] = tmp;
}

void Heapsort(int a[],int N)
{
    int i;
    for (i = N/2;i >= 0;i--)
        PercDown(a,i,N);
    for (i = N-1;i > 0;i--)
    {
        swap(a[0],a[i]);
        PercDown(a,0,i);
    } 
}

int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m))
    {
        for (int i = 0;i < n;i++)    scanf("%d",&a[i]);
        Heapsort(a,n);
        printf("%d",a[0]);
        for (int i = 1;i < m;i++)    printf(" %d",a[i]);
        printf("\n");
    }
    return 0;
}
