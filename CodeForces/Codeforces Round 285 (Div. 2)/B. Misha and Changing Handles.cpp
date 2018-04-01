#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	map<string,string>mp;
	map<string,string>::iterator it;
	set<string>s;
	vector<pair<string,string> >res;
	vector<pair<string,string> >::iterator vit; 
	string OLD,NEW;
	int q;
	scanf("%d",&q);
	for (int i = 0;i < q;i++)
	{
		cin >> OLD >> NEW;
		mp[OLD] = NEW;
		s.insert(NEW);
	}
	for (it = mp.begin();it != mp.end();it++)
	{
		if (s.count(it->first))	continue;
		string val = it->first;
		while (mp.count(val))	val = mp[val];
		res.push_back(make_pair(it->first,val));
	}
	cout << res.size() << endl;
	for (vit = res.begin();vit != res.end();vit++)
	{
		cout << vit->first << " " << vit->second << endl;
	}
	return 0;
}
