#include<stdio.h>
int main()
{
	void min(char &x,char &y);
	char c1,c2,c3;
	while(scanf("%c%c%c",&c1,&c2,&c3)!=EOF){
		getchar();
	    min(c1,c2);
	    min(c1,c3);
	    min(c2,c3);
	    printf("%c %c %c\n",c1,c2,c3); 
	}
	return 0;
}
void min(char &x,char &y)
{
	char temp;
	if(x>y){
		temp=x;
		x=y;
		y=temp;
	}
}
