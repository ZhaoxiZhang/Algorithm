#include<bits/stdc++.h>
using namespace std;
const int maxn = 205;
char str[maxn],a[maxn],b[maxn];

int main(){
	int n,res = 0;
	map<string,string>mp;
	set<string>s;
	set<string>::iterator it;
	scanf("%d",&n);
	getchar();
	for (int i = 0;i < n;i++){
		gets(str);

		int j = 0,len = strlen(str);
		for (j = 0;str[j] != ' ';j++){
			if (str[j] >= 65 && str[j] <= 90){
				str[j] += 32;
			}
		}
		strncpy(a,str,j);
		for (j = len - 1; str[j] != ' ';j--){
			if (str[j] >= 65 && str[j] <= 90){
				str[j] += 32;
			}
		}
		strncpy(b,str + j + 1,len - 1 - j);

		s.insert(a),s.insert(b);
		mp[a] = b;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}

	for (it = s.begin();it != s.end();it++){
		int len = 1;
		string val = *it;
		while (mp.count(val))	val = mp[val],len++;
		res = max(res,len);
	}
	printf("%d\n",res);
	return 0;
}