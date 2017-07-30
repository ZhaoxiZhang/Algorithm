#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	double L,p,q;
	scanf("%lf%lf%lf",&L,&p,&q);
	double t = L/(p+q);
	double len = t*p;
	cout << len << endl;
	return 0;
} 
