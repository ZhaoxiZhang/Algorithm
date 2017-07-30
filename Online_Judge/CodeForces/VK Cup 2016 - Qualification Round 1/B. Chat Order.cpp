#include<bits/stdc++.h>
using namespace std;

vector<string> v(200200);
map<string, int> mp;
set<string> st;

int main()
{
	int n;
    cin >> n;
	for(int i = 0; i < n; i++)
	{
		char buf[20];
		scanf("%s", buf);
		v[i] = buf;
	}
	unsigned size = 0;
	for(int i = n-1; i >=0; i--)
	{
		st.insert(v[i]);
		if(st.size()!=size)
		{
			printf("%s\n", v[i].c_str());
			size++;
		}
	}
    return 0;
}
