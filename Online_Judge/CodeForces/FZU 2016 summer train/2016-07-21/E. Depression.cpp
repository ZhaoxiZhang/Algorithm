#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int hh,ss;
	while (~scanf("%d:%d",&hh,&ss))
	{
		double h,s;
		hh %= 12;
		s = (ss*1.0/60)*360;
		h = (hh*30 + 30*s/360);
		//printf("%lf %lf\n",h,s); 
		cout << h << " " << s << endl;
	}
	return 0;
} 
