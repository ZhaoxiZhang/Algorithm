#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int N,i,k,cnt;
	int flag[30];
	char name[30],data[5];
	
	while (scanf("%d",&N) != EOF)
	{
		if (N == -1) return 0;
		else
		{
			memset(flag,0,sizeof(flag));
			cnt = 0;
			flag[0] = 1;
			name[0] = 'a';
			
			for (i = 0;i < N;i++)
			{
				scanf("%s",data);
				
				if (data[0] == 'a')
				{
					if(flag[data[2] - 'a'] == 0)
					{
						flag[0] = 0;
					}
				}
				else if (flag[data[2] - 'a'] == 1)
				{
					cnt++;
					flag[data[0] - 'a'] = 1;
					name[data[0] - 'a'] = data[0];
				}
			}
		}
		k = 0;
		for (i = 0;i < 26;i++)
		{
			if (flag[i])
			{
				k++;
				if(k == 1) printf("%c",name[i]);
				else printf(" %c",name[i]);
			}
		}
		if (!k) printf("none");
		printf("\n");
	}
	return 0;
} 
