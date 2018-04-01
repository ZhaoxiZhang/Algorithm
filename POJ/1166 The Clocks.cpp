#include<iostream>
#include<cstdio>
using namespace std;
int a[10] = {0},b[10] = {0},c[10] = {0};

int main()
{
	for (int i = 0;i < 9;i++)	scanf("%d",&a[i]);
	for (b[0] = 0;b[0] < 4;b[0]++)
		for (b[1] = 0;b[1] < 4;b[1]++)
			for (b[2] = 0;b[2] < 4;b[2]++)
				for (b[3] = 0;b[3] < 4;b[3]++)
					for (b[4] = 0;b[4] < 4;b[4]++)
						for (b[5] = 0;b[5] < 4;b[5]++)
							for (b[6] = 0;b[6] < 4;b[6]++)
								for (b[7] = 0;b[7] < 4;b[7]++)
									for (b[8] = 0;b[8] < 4;b[8]++)
									{
										c[0] = (a[0] + b[0] + b[1] + b[3])%4;
										c[1] = (a[1] + b[0] + b[1] + b[2] + b[4])%4;
										c[2] = (a[2] + b[1] + b[2] + b[5])%4;
										c[3] = (a[3] + b[0] + b[3] + b[4] + b[6])%4;
										c[4] = (a[4] + b[0] + b[2] + b[4] + b[6] + b[8])%4;
										c[5] = (a[5] + b[2] + b[4] + b[5] + b[8])%4;
										c[6] = (a[6] + b[3] + b[6] +b[7])%4;
										c[7] = (a[7] + b[4] + b[6] + b[7] + b[8])%4;
										c[8] = (a[8] + b[5] + b[7] + b[8])%4;
										if (!c[0] && !c[1] && !c[2] && !c[3] && !c[4] && !c[5] && !c[5] && !c[6] && !c[7] && !c[8])
										{
											while (b[0]--)	printf("1 ");
											while (b[1]--)	printf("2 ");
											while (b[2]--)	printf("3 ");
											while (b[3]--)	printf("4 ");
											while (b[4]--)	printf("5 ");
											while (b[5]--)	printf("6 ");
											while (b[6]--)	printf("7 ");
											while (b[7]--)	printf("8 ");
											while (b[8]--)	printf("9 ");
											printf("\n");
											return 0;											
										}
									}
	return 0;
}
