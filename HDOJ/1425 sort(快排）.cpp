#include<bits/stdc++.h>
using namespace std;
#define Cutoff (3)
const int maxn = 1000005;
int a[maxn];

void InsertionSort(int a[],int N)
{
	int i,j,tmp;
	for (i = N - 2;i >= 0;i--)
	{
		tmp = a[i];
		for (j = i;j < N - 1 && a[j + 1] > tmp;j++)
			a[j] = a[j + 1];
		a[j] = tmp;
	}
}

int median3(int a[],int left,int right)
{
	int center = (left + right) / 2;
	if (a[left] < a[center])
		swap(a[left],a[center]);
	if (a[left] < a[right])
		swap(a[left],a[right]);
	if (a[center] < a[right])
		swap(a[center],a[right]);
	swap(a[center],a[left + 1]);
	return a[left + 1];
}

void qsort(int a[],int left,int right)
{
	int i,j,pivot;
	if (left + Cutoff <= right)
	{
		pivot = median3(a,left,right);
		i = left + 1;j = right;
		for (;;)
		{
			while (a[++i] > pivot){}
			while (a[--j] < pivot){}
			if (i < j)	swap(a[i],a[j]);
			else	break;
		}
		swap(a[j],a[left + 1]);
		qsort(a,left,j - 1);
		qsort(a,j + 1,right);
	}
	else	InsertionSort(a + left,right - left + 1);
}

int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m))
	{
		for (int i = 0;i < n;i++)	scanf("%d",&a[i]);
		qsort(a,0,n - 1);
		printf("%d",a[0]);
		for (int i = 1;i < m;i++)	printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
} 
