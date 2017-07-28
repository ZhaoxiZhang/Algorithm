#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn = 5005;
int sum;
void merge_array(int array[],int left,int mid,int right)
{
	if (left >= right)	return;
	int i = left,j = mid + 1,k = 0;
	int *p;
	p = (int *)malloc((right - left + 1)*sizeof(int));
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
		{
			p[k++] = array[i++];
		}
		else
		{
			p[k++] = array[j++];
			sum += mid - i + 1;
		}
	}
	while (i <= mid)
	{
		p[k++] = array[i++];
	}
	while (j <= right)
	{
		p[k++] = array[j++];
	}
	for (int i = 0;i < k;i++)
	{
		array[i+left] = p[i];
	}
	free(p);
}

void merge_sort(int array[],int left,int right)
{
	if (left >= right)	return;
	int mid = (left + right)>>1;
	merge_sort(array,left,mid);
	merge_sort(array,mid + 1,right);
	merge_array(array,left,mid,right);
}

int main()
{
	int N;
	while (~scanf("%d",&N))
	{
		int a[maxn],b[maxn],res;
		sum = 0;
		for (int i = 0;i < N;i++)
		{
			scanf("%d",&a[i]);
			b[i] = a[i];
		}
		merge_sort(a,0,N - 1);
		res = sum;
		for (int i = 0;i < N;i++)
		{
			sum += N - b[i] - b[i] - 1;
			res = min(res,sum);
		}
		printf("%d\n",res);
	}
	return 0;
}
