#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
int lson[maxn] = {0},rson[maxn] = {0};

void preorder(int x)
{
	if (x != 1)	printf(" ");
	printf("%d",x);
	if (lson[x])	preorder(lson[x]);
	if (rson[x])	preorder(rson[x]);
}

void inorder(int x)
{
	if (x)
	{
		inorder(lson[x]);
		printf("%d ",x);
		inorder(rson[x]); 
	}
}

void postorder(int x)
{
	if (lson[x])	postorder(lson[x]);
	if (rson[x])	postorder(rson[x]);
	printf("%d ",x); 
}

int main()
{
	int N;
	scanf("%d",&N);
	for (int i = 1;i <= N;i++)	scanf("%d%d",&lson[i],&rson[i]);
	preorder(1);printf("\n");
	inorder(1);printf("\n");
	postorder(1);printf("\n");
	return 0;
}
