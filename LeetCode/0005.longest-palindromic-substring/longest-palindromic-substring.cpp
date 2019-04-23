class Solution {
public:
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
        
        //for (int i = 0;i < 2*len + 2;i++)	res = max(res,p[i] - 1);
        
        //cout << res << endl;
        
        for (int i = 0;i < 2*len + 2;i++){
            if (p[i] > length){
                
                length = p[i];
                pos = i;
            }
        }
        //cout << str << endl;
        //cout << pos << " " << res << endl;
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
};