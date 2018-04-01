#include<stdio.h>
#include<string.h>
struct Des {
	char letter[20];
	int val;
};
int main()
{
	struct Des job[1005];
	int M,N,sum;
	char ans[20];

	scanf("%d%d",&M,&N);

	for (int i = 0; i < M; i++)
	{
		scanf("%s%d",job[i].letter,&job[i].val);
	}

	while (N--)
	{
		sum = 0;
		while (scanf("%s",ans) && strcmp(ans,"."))
		{
			for (int i = 0; i < M; i++)
			{
				if (strcmp(ans,job[i].letter) == 0)
				{
					sum += job[i].val;
				}
			}
		}
		printf("%d\n",sum);
	}

	return 0;
}
