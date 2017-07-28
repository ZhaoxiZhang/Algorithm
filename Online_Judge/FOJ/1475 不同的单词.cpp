#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

string transform(string str)
{
	int len = str.size();
	for (int i = 0; i < len;i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') 
		{
			str[i] += 32;
		}
	}
	return str;
} 

int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		string words;
		set<string>word_count;
		word_count.clear();
		cin.get();
		for (int i = 0;i < n;i++)
		{
			getline(cin,words);
			words = transform(words);
			word_count.insert(words);
		}
		
		printf("%d\n",word_count.size());
	}
	return 0;
}
