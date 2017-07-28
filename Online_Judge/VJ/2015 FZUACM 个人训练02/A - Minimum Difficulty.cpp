#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	int N,max = 0,min;
	int ans[105];
	scanf("%d",&N);
	for (int i = 0;i < N;i++)
	{
		scanf("%d",&ans[i]);
	}
	for (int i = 1;i < N-1;i++)
    {
        for (int j = 1;j < N-1;j++)
        {
            if (j == i)
            {
                if (ans[j+1] - ans[j-1] > max)
                {
                    max = ans[j+1] - ans[j-1];
                }
            }
            else if (j - 1 == i)
            {
                if (ans[j] - ans[j-2] > max)
                {
                    max = ans[j] - ans[j-2];
                }
            }
            else
            {
                if (ans[j] - ans[j-1] > max)
                {
                    max = ans[j] - ans[j-1];
                }
            }
        }
        if (i == 1)
		{
			min = max;
		} 
        if (max < min)
        {
            min = max;
        }
    }
    printf("%d\n",min);
	return 0;
}

