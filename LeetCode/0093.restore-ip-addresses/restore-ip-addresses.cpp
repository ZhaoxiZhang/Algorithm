class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        restoreIp(s, res, 0, "", 0);
        return res;
    }

    void restoreIp(string ip, vector<string>& res, int idx, string restored, int count){
        if (count > 4)  return;
        if (count == 4 && idx == ip.size()) res.push_back(restored);

        for (int i = 1; i < 4; i++){
            if (idx + i > ip.size())    break;
            string s = ip.substr(idx, i);
            if ((s[0] == '0' && s.size() > 1) || (i == 3 && to_int(s) >= 256))  continue;
            restoreIp(ip, res, idx + i, restored + s + (count == 3 ? "" : "."), count + 1);
        }
    }
    
    int to_int(string str){
        int size = str.size();
        int res = 0, base = 1;
        for (int i = size - 1; i >= 0; i--){
            res += (str[i] - '0') * base;
            base *= 10;
        }
        return res;
    }
};