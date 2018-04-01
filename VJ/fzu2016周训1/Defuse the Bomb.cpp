#include<cstdio>
using namespace std;
int resbot[10] = {0},respos[10] = {0},num[10] = {0};

void Stage1(int dis)
{
	if (dis == 1)
	{
		respos[1] = 2;
		resbot[1] = num[2];
	}
	else if (dis == 2)
	{
		respos[1] = 2;
		resbot[1] = num[2];
	}
	else if (dis == 3)
	{
		respos[1] = 3;
		resbot[1] = num[3];
	}
	else if(dis == 4)
	{
		respos[1] = 4;
		resbot[1] = num[4];
	}
}

void Stage2(int dis)
{
	if (dis == 1)
	{
		for (int i = 1;i < 5;i++)
		{
			if (num[i] == 4)
			{
				respos[2] = i;
				resbot[2] = 4;
			}
		}
	}
	else if (dis == 2)
	{
		respos[2] = respos[1];
		resbot[2] = num[respos[1]];
	}
	else if (dis == 3)
	{
		respos[2] = 1;
		resbot[2] = num[1];
	}
	else if (dis == 4)
	{
		respos[2] = respos[1];
		resbot[2] = num[respos[1]];
	}
}

void Stage3(int dis)
{
	if (dis == 1)
	{
		for (int i = 0;i < 5;i++)
		{
			if (num[i] == resbot[2])
			{
				respos[3] = i;
				resbot[3] = resbot[2];
			}
		}
	}
	else if (dis == 2)
	{
		for (int i = 0;i < 5;i++)
		{
			if (num[i] == resbot[1])
			{
				respos[3] = i;
				resbot[3] = resbot[1];
			}
		}
	}
	else if (dis == 3)
	{
		respos[3] = 3;
		resbot[3] = num[3];
	}
	else if (dis == 4)
	{
		for (int i = 1;i < 5;i++)
		{
			if (num[i] == 4)
			{
				respos[3] = i;
				resbot[3] = 4;
			}
		}
	}
}

void Stage4(int dis)
{
	if (dis == 1)
	{
		respos[4] = respos[1];
		resbot[4] = num[respos[1]];
	}
	else if (dis == 2)
	{
		respos[4] = 1;
		resbot[4] = num[1];
	}
	else if (dis == 3)
	{
		respos[4] = respos[2];
		resbot[4] = num[respos[2]];
	}
	else if (dis == 4)
	{
		respos[4] = respos[2];
		resbot[4] = num[respos[2]];
	}
} 

void Stage5(int dis)
{
	if (dis == 1) 
	{
		for (int i = 1; i < 5;i++)
		{
			if (num[i] == resbot[1])
			{
				respos[5] = i;
				resbot[5] = resbot[1];
			}
		}
	}
	else if (dis == 2)
	{
		for (int i = 1; i < 5;i++)
		{
			if (num[i] == resbot[2])
			{
				respos[5] = i;
				resbot[5] = resbot[2];
			}
		}
	}
	else if (dis == 3)
	{
		for (int i = 1; i < 5;i++)
		{
			if (num[i] == resbot[4])
			{
				respos[5] = i;
				resbot[5] = resbot[4];
			}
		}
	}
	else if (dis == 4)
	{
		for (int i = 1; i < 5;i++)
		{
			if (num[i] == resbot[3])
			{
				respos[5] = i;
				resbot[5] = resbot[3];
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int D;
		for (int i = 1;i <= 5;i++)
		{
			scanf("%d%d%d%d%d",&D,&num[1],&num[2],&num[3],&num[4]);
			if (i == 1)
			{
				Stage1(D);
			}
			else if (i == 2)
			{
				Stage2(D);
			}
			else if (i == 3)
			{
				Stage3(D);
			}
			else if (i == 4)
			{
				Stage4( D);
			}
			else if (i == 5)
			{
				Stage5(D);
			}
			printf("%d %d\n",respos[i],resbot[i]);
		}
	}
	return 0;
}
