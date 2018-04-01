#include<stdio.h>
#include<string.h>
int ans[100005];

int main()
{
	int N;
	
	while (scanf("%d",&N) != EOF)
	{
		memset(ans,0,sizeof(ans));
		
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&ans[i]);
		}
		
		int q;
		
		scanf("%d",&q);
		
		while (q--)
		{
			int L,R;
			
			scanf("%d%d",&L,&R);
			
			int flag = 0;
			for (int dis = R - L; dis >= 0;dis--)
			{
				for (int i = L;i <= R;i++)
				{
					if (ans[i] == ans[R])
					{
						int j = R - i;
						printf("%d\n",j);
						flag = 1; 
						break;
					}
				}
				if (flag)
				{
					break;
				} 
			}
		}
	}
	
	return 0;
} 
