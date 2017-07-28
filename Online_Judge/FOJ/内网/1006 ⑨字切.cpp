#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int N,M;
	while (~scanf("%d%d",&N,&M))
	{
		int res,sum,i,j,k;
		int mat[105][105];
		int matsum[105][105];
		memset(mat,0,sizeof(mat));
		memset(matsum,0,sizeof(matsum));
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < M;j++)
			{
				scanf("%d",&mat[i][j]);
			}
		}
		for (i = 0;i < N;i++)
		{
			for (matsum[i][j=0]=0;j < M;j++)
			{
				 matsum[i][j+1] = matsum[i][j] + mat[i][j];
				 cout << matsum[i][j+1] << " ";
			}
			cout << endl;
		} 
		for (int i =0;i < N;i++)
		{
			for (int j = 0;j <= M;j++)
			{
				printf("%d ",matsum[i][j]);
			}
			printf("\n");
		}
		for (res = mat[0][j=0];j<M;j++)
		{
			for (k = j;k < M;k++)
			{
				for (sum = 0,i = 0;i < N;i++)
				{
					sum = (sum > 0?sum:0)+matsum[i][k+1] - matsum[i][j],res = (sum>res?sum:res);
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
