#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	//472ms
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int len = s.size();
        for (int i = 0;i < len;i++) mp[s[i]] = 0;
        int st = 0, ed = 0,res = 0;
        for (;;){
            while (ed < len && !mp[s[ed]]){
                mp[s[ed]] = ed + 1;
                ed++;
            }
            if (ed > len)    break;
            res = max(res,ed - st);
            if (ed >= len)  break;
			st = ed = mp[s[ed]];
            mp.clear();
        }
        return res;
    }

    //18ms
    int lengthOfLongestSubstring(string s) {
        int pos[256];
        memset(pos,-1,sizeof(pos));
        int st = 0,ed = 0,res = 0;
        int len = s.size();
        for (int i = 0;i < len;i++){
        	int index = s[i];
        	if (pos[index] == -1 || pos[index] < st){
        		pos[index] = i;
        		res = max(res,i - st + 1);
        	}else{
        		st = pos[index] + 1;
				pos[index] = i;
        	}
        }
        return res;
    }

};

int main(){
	//freopen("input.txt","r",stdin);
    string s;
    cin >> s;
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
