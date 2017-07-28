#include<stdio.h>

int gcd(int m,int n)
{
	int tmp;
	if (m < n)
	{
		tmp = m;
		m = n;
		n = tmp;
	}
	
	if (m % n == 0)
	{
		return n;
	}
	else
	{
		return gcd(n,m%n);
	}
}

int main()
{
	int N,i;
	
	scanf("%d",&N);
	
	while (N--)
	{
		double num1,num2;
		int sum1,sum2 = 1,fac;
		
		scanf("%lf",&num1);
		
		for (i = 1;i <= 9;i++)
		{
			num1 *= 10;
			sum2 *= 10;
			num2 = num1 + 0.000001;    //由于double类型的精度问题，如“1”，double可能以“0.99999……”保存，
			                           // 所以加一个极小的小数使之能得到想要的整数 
			if (num1 - (int)num2 <= 0.000001)   //还是由于double的精度问题，可能printf输出的num1值和(int)num2）值 
			{                                   //相同 ，但是内部这两个数由于小数位的问题是不等的，判断相等方法就用二者差值是否极小 
				break;
			}
		}
		
		sum1 = (int)num2;
		
		fac = gcd(sum1,sum2);
		
		printf("%d/%d\n",sum1/fac,sum2/fac);
	}
	
	return 0;
}
