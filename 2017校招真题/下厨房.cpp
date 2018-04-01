#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
char str[maxn];
set<string>s;

int main(){
    //freopen("input.txt","r",stdin);
    while (~scanf("%s",str)){
        s.insert(str);
    }
    cout << s.size() << endl;
    return 0;
}
