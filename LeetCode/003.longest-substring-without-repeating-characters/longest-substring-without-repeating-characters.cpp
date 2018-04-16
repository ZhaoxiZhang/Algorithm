class Solution {
public:
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