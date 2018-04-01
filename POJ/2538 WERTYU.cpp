#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	string str="`1234567890-=QWERTYUIOP[]\ASDFGHJKL;''ZXCVBNM,./";
	string letter;
	while (getline(cin,letter))
	{
		int len = letter.size();
		for (int i = 0;i < len;i++)
		{
			if (letter[i] == ' ')
			{
				cout << " ";
			}
			else
			{
				int pos = str.find(letter[i]);
				cout << str[pos - 1];
			}
		}
		cout << endl; 
	}
	return 0;
} 
