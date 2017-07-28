#include<iostream>
#include<string>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
	string NameOfCadite,NameOfParty,ballot,winner;
	int N,M;

	while(scanf("%d",&N) != EOF)
	{
		map<string,string>cadite1;
		map<string,int>cadite2;
		map<string,string>::iterator it;
		int max = 0,flag = 0;

		cin.get();

		while (N--)
		{
			getline(cin,NameOfCadite);
			getline(cin,NameOfParty);

			cadite1[NameOfCadite] = NameOfParty;   //建立竞选人及其所在党派的关联容器
		}

		cin >> M;
		cin.get();   //读入空行 

		while (M--)
		{
			getline(cin,ballot);
			it = cadite1.find(ballot);     //查找是否有键值为'ballot'的元素 
			if (it == cadite1.end())       //没找到，跳过 
			{
				continue;
			}
			else
			{
				cadite2[ballot]++;
				int tmp = cadite2[ballot];
				if (tmp > max)            //选出票数最多的竞选人 
				{
					flag = 1;            //有最多票数的情况 
					winner = ballot;     //记录票数最多的竞选人名字，通过“名字”关键字找出所在党派
					max = tmp;          //更新最大值
				}
				else if (tmp == max)
				{
					flag = 0;         //存在票数至少两个相同的情况
				}
			}
		}

		if (flag)
		{
			if (cadite1[winner] == "independent")
			{
				cout << "independent" << endl;
			}
			else
			{
				cout << cadite1[winner] << endl;
			}
		}
		else
		{
			cout << "tie" << endl;
		}
	}
	return 0;
}
