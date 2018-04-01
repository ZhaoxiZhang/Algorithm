#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int maxn = 1005;
int sum = 0;
void merge_array(int array[],int left,int mid,int right)
{
	if (left >= right)	return;
	int i = left,j = mid + 1,k = 0;
	int *p;
	p = (int *)malloc((right-left+1)*sizeof(int));
	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])	p[k++] = array[i++];
		else	p[k++] = array[j++],sum += mid - i + 1;
	}
	while (i <= mid)	p[k++] = array[i++];
	while (j <= right)	p[k++] = array[j++];
	for (i = 0;i < k;i++)	array[i+left] = p[i];
	free(p);
}

void merge_sort(int array[],int left,int right)
{
	if (left >= right)	return;
	int mid = left + ((right - left)>>1);
	merge_sort(array,left,mid);
	merge_sort(array,mid+1,right);
	merge_array(array,left,mid,right);
}

int main()
{
	int T,Case = 0;
	scanf("%d",&T);
	while (T--)
	{
		int N,a[maxn];
		scanf("%d",&N);
		for (int i = 0;i < N;i++)	scanf("%d",&a[i]);
		sum = 0;
		merge_sort(a,0,N-1);
		printf("Scenario #%d:\n%d\n\n",++Case,sum);
	} 
	return 0;
}
