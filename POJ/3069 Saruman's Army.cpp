#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
	return a < b;
} 

int main()
{
	int R,N,i,tmp,flag,cnt;
	int ans[1005];
	
	while (cin >> R >> N)
	{
		if (R == -1 && N == -1)
		{
			return 0;
		}
		
		for (i = 0;i < N;i++)
		{
			cin >> ans[i];
		}
		
		sort(ans,ans + N,cmp);
		i = 0;
		cnt = 0;
		
		while (i < N)
		{
			tmp = ans[i];
			
			while (i < N && ans[i] <= tmp + R)
			{
				i++;
			}
			
			flag = ans[i-1];
			
			while (i < N && ans[i] <= flag + R)
			{
				i++;
			}
			cnt++;
		}
		cout << cnt <<endl;
	}
	return 0;
}
