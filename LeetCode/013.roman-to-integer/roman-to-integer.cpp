class Solution {
public:
    int romanToInt(string s) {
        int size = s.size() - 1;
        int res = 0;
        int i;
        for (i = 0; i < size; i++){
            if (s[i] == 'I'){
                if (s[i + 1] == 'V')    res += 4, i++;
                else if (s[i + 1] == 'X')    res += 9, i++;
                else res += 1;
            }else if (s[i] == 'V'){
                res += 5;
            }else if (s[i] == 'X'){
                if (s[i + 1] == 'L')    res += 40, i++;
                else if (s[i + 1] == 'C')   res += 90, i++;
                else res += 10;
            }else if (s[i] == 'L'){
                res += 50;
            }else if (s[i] == 'C'){
                if (s[i + 1] == 'D')    res += 400, i++;
                else if (s[i + 1] == 'M')   res += 900, i++;
                else res += 100;
            }else if (s[i] == 'D'){
                res += 500;
            }else if (s[i] == 'M'){
                res += 1000;
            }
        }
    
        if (i <= size){
            if (s[size] == 'I') res += 1;
            else if (s[size] == 'V')    res += 5;
            else if (s[size] == 'X')    res += 10;
            else if (s[size] == 'L')    res += 50; 
            else if (s[size] == 'C')    res += 100;
            else if (s[size] == 'D')    res += 500;
            else if (s[size] == 'M')    res += 1000;
        }
        

        return res;

    }
};