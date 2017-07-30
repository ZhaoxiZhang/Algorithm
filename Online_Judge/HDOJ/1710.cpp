#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
typedef struct Tree{
	Tree *left,*right;
	int val;
}Tree;
Tree *head;
Tree *build(int a[],int b[],int N)
{
	Tree *node;
	for (int i = 0;i < N;i++)
	{
		if (b[i] == a[0])
		{
			node = (Tree *)malloc(sizeof(Tree));
			node->val = a[0];
			node->left = build(a + 1,b,i);
			node->right = build(a + i + 1,b + i + 1, N - i - 1);
			return node;
		}
	}
	return NULL;
}

void Print(Tree *p)
{
	if (p == NULL)	return;
	Print(p->left);
	Print(p->right);
	if (p == head)	printf("%d\n",p->val);
	else	printf("%d ",p->val);
	free(p);
}

int main()
{
	int N,a[maxn],b[maxn];
	while (~scanf("%d",&N))
	{
		for (int i = 0;i < N;i++)	scanf("%d",&a[i]);
		for (int i = 0;i < N;i++)	scanf("%d",&b[i]);
		head = build(a,b,N);
		Print(head);
	}
	return 0;
}
