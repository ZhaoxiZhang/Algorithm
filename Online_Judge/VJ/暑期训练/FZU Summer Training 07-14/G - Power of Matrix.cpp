#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 50;
const int mod = 10;

struct Matrix
{
    int mat[50][50];
    int r,c;
    Matrix(int r1 = 0,int c1 = 0):r(r1),c(c1)
    {
        memset(mat,0,sizeof(mat));
    }
    void E()
    {
        memset(mat,0,sizeof(mat));
        for (int i = 0;i < r;i++)
        {
        	for (int j = 0;j < c;j++)
        	{
        		mat[i][j] = (i == j);
        	}
        }
    }
    Matrix operator+(const Matrix & m)
    {
        Matrix res(r,c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                res.mat[i][j] = (mat[i][j] + m.mat[i][j])%mod;
            }
        }
        return res;
    }

    Matrix operator * (const Matrix & m)
    {
        Matrix res(r,m.c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < m.c; j++)
            {
				for (int k = 0; k < c; k++)
                {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * m.mat[k][j])%mod;
                }
            }
        }
        return res;
    }
    void show()
    {
    	for (int i = 0;i < r;i++)
		{
			bool first = true;
			for (int j = 0;j < c;j++)
			{
				first?printf("%d",mat[i][j]):printf(" %d",mat[i][j]);
				first = false;
			}
			printf("\n");
		} 
    }
};

Matrix pow(Matrix x,int n)
{
	Matrix res(x.r,x.c);
	res.E();
	while (n > 0)
	{
		if (n&1)
		{
			res = res * x;
		}
		x = x * x;
		n >>= 1;
	}
	return res;
}

Matrix sum(Matrix mat,int k)
{
	if (k == 1)
	{
		return mat;
	}
	Matrix E(mat.r,mat.c);
	E.E();
	if (k&1)
	{
		return (E + pow(mat,k/2))*sum(mat,k/2) + pow(mat,k);
	}
	else
	{
		return (E + pow(mat,k/2))*sum(mat,k/2);
	}
}


int main()
{
    int n,k;
    while (~scanf("%d%d",&n,&k) && n && k)
    {
        Matrix Mat(n,n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d",&Mat.mat[i][j]);
                Mat.mat[i][j] %= mod;
            }
        }
        if (k == 0)
        {
        	Mat.show();
        	continue;
        }
        Mat = sum(Mat,k);
        Mat.show();
        printf("\n");
    }
    return 0;
}
