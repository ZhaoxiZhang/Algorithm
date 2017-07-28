#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    while (N--)
    {
        int p,e,i,d,j;
        int Case = 1;
        while (~scanf("%d%d%d%d",&p,&e,&i,&d) && p != -1 && e != -1 && i != -1 && d != -1)
        {
            for (j = d+1; j < 21252; j++)
                if ((j - p)%23 == 0)
                    break;
            for (; j < 21252; j += 23)
                if((j - e) % 28 == 0)
                    break;
            for (; j < 21252; j += 23*28)
                if ((j - i) % 33 == 0)
                    break;
            printf("Case %d",Case++);
            printf(": the next triple peak occurs in %d days.\n",j - d);
        }
        if (N)	printf("\n");
    }
    return 0;
}
