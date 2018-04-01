#include <stdio.h>

int main()
{
    int x, y, sum, i, count, n;
    while(scanf("%d %d", &x, &y) != EOF && (x!=0 || y!= 0))
    {
        count = 0;
        for(n = x; n <= y; ++n)
        {
            sum = n * n + n + 41;
            for(i = 2; i * i <= sum; ++i)
            {
                if(sum % i == 0)
                    count = 1;
            }        
        }
        if(count == 0)
            printf("OK\n");
        else 
            printf("Sorry\n");
        
    }
    return 0;
}
