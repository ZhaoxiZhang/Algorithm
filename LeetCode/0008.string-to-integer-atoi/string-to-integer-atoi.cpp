class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        char cstr[size + 5];
        bool isNegative = false;
        long long res = 0;
        memset(cstr, 0, sizeof(cstr));

        for (int i = 0; i < size; i++)  cstr[i] = str[i];

        int index = 0;

        //跳过空格
        while (cstr[index] == ' ')  index++;

        //第一个非空字符是 '+' '-' [0-9]
        if (cstr[index] == '-' || cstr[index] == '+' || (cstr[index] >= '0' && cstr[index] <= '9')) {
            int start = 0, end = 0;

            if (cstr[index] == '-') {
                isNegative = true;
                index++;
            } else if (cstr[index] == '+') {
                isNegative = false;
                index++;
            }
            
            //跳过 0
            while (cstr[index] == '0')  index++;

            start = index;

            while (cstr[index] >= '0' && cstr[index] <= '9')    index++;

            end = index;

            long long base = 1;
            if (end - start > 10) {
                if (isNegative) res = INT_MIN;
                else    res = INT_MAX;
            } else {
                for (int i = end - 1; i >= start; i--) {
                    res += (cstr[i] - '0') * base;
                    base *= 10;
                }
                
                if (isNegative) res = -res;

                if (res < INT_MIN)  res = INT_MIN;
                if (res > INT_MAX)  res = INT_MAX;
            }

        }
        return (int)res;
    }
};