#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	//9ms
    string longestPalindrome(string s) {
        int p[2005];
        char str[2005];

        int len = s.size();
        int pos = 0;

        str[pos++] = '$';
        str[pos++] = '#';
        for (int i = 0;i < len;i++){
            str[pos++] = s[i];
            str[pos++] = '#';
        }
        str[pos] = 0;
        int mx = 0,id = 0;
        for (int i = 0;i < pos;i++){
            p[i] = mx > i ? min(p[2*id - i],mx - i) : 1;
            while (i - p[i] >= 0 && str[i + p[i]] == str[i - p[i]])  p[i]++;
            if (i + p[i] > mx){
                mx = i + p[i];
                id = i;
            }
        }

        int length = 0;
        for (int i = 0;i < 2*len + 2;i++){
            if (p[i] > length){

                length = p[i];
                pos = i;
            }
        }

        s = "";
        for (int i = pos - length + 1,j = 0;j < length;i++,j++){
        	if (str[i] == '#' || str[i] == '$')	continue;
        	s += str[i];
        }
        for (int i = pos + 1,j = 0;j < length - 1;i++,j++){
        	if (str[i] == '#' || str[i] == '$')	continue;
        	s += str[i];
        }
        return s;
    }

    //3ms
    string longestPalindrome(string s) {
        if (s.size()<2) return s;
        string res;
        int max_l = 0;
        for (int i=0; i<s.size();)
        {
            int j = i, k = i;
            while (k<s.size()-1 && s[k+1]==s[i]) k++;
            i = k+1;
            while (j>0 && k<s.size()-1 && s[j-1]==s[k+1]) {j--;k++;}
            if ((k-j+1)>max_l)
            {
                max_l = k-j+1;
                res = s.substr(j,k-j+1);
            }
        }
        return res;
    }



};

int main(){
	Solution solution;
	string s;
	cin >> s;
	cout << solution.longestPalindrome(s) << endl;
	return 0;
}
