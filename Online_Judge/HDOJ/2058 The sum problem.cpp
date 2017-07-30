#include<stdio.h>
#include<math.h>

int main()
{
    int N,M,val,len;
    while (~scanf("%d%d",&N,&M) && N && M)
    {
		len = (int)sqrt(2*M);
        while (len--)
        {
            val = M / (len + 1) - len /2;
            if ((2*val+len) * (len+1) / 2 == M)
                printf("[%d,%d]\n", val, val+len);
        }
        printf("\n");
    }
    return 0;
}
