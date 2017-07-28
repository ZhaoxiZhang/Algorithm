#include<iostream>
#include<sstream>
#include<set>
#include<string>
using namespace std;

int main()
{
	set<string>word_count;
	stringstream tmp;
	string word;
	
	while (getline(cin,word) && word != "#")
	{
		stringstream tmp(word);
		word_count.clear();
		while (tmp >> word)
		{
			word_count.insert(word);
		}
		
		cout << word_count.size() << endl;
	 } 
}
