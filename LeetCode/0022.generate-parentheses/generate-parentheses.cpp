class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string str;
        generate(res, str, n, n, 2 * n);
        for (auto val : res)	cout << val << endl;
        return res;
    }

    void generate(vector<string> &res, string str, int left, int right, int size){
        if (str.size() == size){
            if (valid(str, true)){
            	//cout << str << endl;
                res.push_back(str);
            }
        }else{
            if (left > 0 && valid(str + '(', false)){
                generate(res, str + "(", left - 1, right, size);
            }
            if (right > 0 && valid(str + ')', false)){
                generate(res, str + ")", left, right - 1, size);
            }
            
        }

    }

    bool valid(string str, bool final){
        int size = str.size();
        int left = 0;
        for (int i = 0; i < size; i++){
            if (str[i] == '(')  left++;
            if (str[i] == ')')  left--;
            if (left < 0)   return false;
        }
        return final ? left == 0 : true;;
    }
};