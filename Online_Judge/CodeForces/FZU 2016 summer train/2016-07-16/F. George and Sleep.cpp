#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int chh,css,nhh,nss,bhh,bss;
	scanf("%d:%d",&chh,&css);
	scanf("%d:%d",&nhh,&nss);
	if (chh == 0)
	{
		chh = 24;
	}
	if (nss <= css)
	{
		bss = css - nss;
	}
	else
	{
		bss = css+60-nss;
		chh--;
	}
	if (chh < nhh)
	{
		bhh = chh +24 - nhh;
	}
	else
	{
		bhh = chh - nhh;
	}
	if (bhh == 24)
	{
		bhh = 0;
	}
	printf("%02d:%02d\n",bhh,bss);
	return 0;
} 
