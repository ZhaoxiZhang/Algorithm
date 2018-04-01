#include<bits/stdc++.h>
using namespace std;
string in,post;

void pre(string in,string post)
{
	if (post.empty())	return;
	int pos,len = post.size();
	char ch = post[len-1];
	cout << ch;
	pos = in.find(ch);
	pre(in.substr(0,pos),post.substr(0,pos));
	pre(in.substr(pos + 1,len - pos - 1),post.substr(pos,len - pos - 1));
}

int main()
{
	cin >> in >> post;
	pre(in,post);
	return 0;
} 
