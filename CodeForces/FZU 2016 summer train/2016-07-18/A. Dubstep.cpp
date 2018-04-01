#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string str,tmp;
	cin >> str;
	int len = str.size();
	for (int i = 0;i < len;)
	{
		string s = str.substr(i,3);
		if (s == "WUB")
		{
			i += 3;
		}
		else
		{
			tmp += str[i];
			i++;
			string s = str.substr(i,3);
			if (s == "WUB")
			{
				tmp += ' ';
			}
		}
	}
	if (tmp != "")
		cout << tmp << endl;
	return 0;
} 
