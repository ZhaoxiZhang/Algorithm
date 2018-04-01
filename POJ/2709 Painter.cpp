#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int color[15];
	int N,gray,num,i;

	while (cin >> N && N)
	{

		for (i = 0; i < N; i++)
		{
			cin >> color[i];
		}

		cin >> gray;

		for (i = 0; i < gray; i++)
		{
			sort(color,color + N);
			color[0]++;
			color[1]++;
			color[2]++;
		}
		sort(color,color + N);

		num = color[N - 1] / 50;

		if (color[N - 1] % 50 != 0)
		{
			num++;
		}

		cout << num << endl;
	}
	return 0;
}
