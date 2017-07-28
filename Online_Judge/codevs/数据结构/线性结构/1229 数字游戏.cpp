#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,M,X,K;
bool flag;

int pow(int x,int n)
{
	int res = 1;
	while (n)
	{
		if (n & 1)
		{
			res *= x;
		}
		x *= x;
		n >>= 1;
	}
	return res;
}


void permutation(int n,int *P,int *A,int cur) //输入数组P，并按字典序输出数组A各元素的所有全排列
{
    if (cur == n)
    {
        int T = 0;
        for (int i = 0;i < n;i++)	T += A[i]*pow(10,n-i-1);
        //printf("%d\n",T);
        if ((T+X) % K == 0)
        {
        	flag = true;
			for (int i = 0;i < n;i++)	i?printf("%d",A[i]):printf("%d",A[i]);
        	printf("\n");
        }
    }
    else for (int i = 0; i < n; i++)
    {
        if (!i || P[i] != P[i-1])
        {
            int c1 = 0,c2 = 0;
            for (int j = 0; j < cur; j++)    if (A[j] == P[i])   c1++;
            for (int j = 0; j < n; j++)  if (P[i] == P[j])   c2++;
            if (c1 < c2)
            {
                A[cur] = P[i];
                permutation(n,P,A,cur+1);
                if (flag)	return;
            }
        }
    }
}


int main()
{
	int p[15],a[15];
	scanf("%d%d",&N,&M);
	for (int i = 0;i < N;i++)	scanf("%d",&p[i]); 
	while (M--)
	{
		scanf("%d%d",&X,&K);
		flag = false;
		permutation(N,p,a,0);
		if (!flag)	printf("None\n");
	}
}
