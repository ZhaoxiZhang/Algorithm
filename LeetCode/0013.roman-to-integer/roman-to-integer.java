class Solution {
    public int romanToInt(String s) {
        int length = s.length() - 1;
        char[] cstr = s.toCharArray();
        int res = 0;
        int i;
        for (i = 0; i < length; i++){
            if (cstr[i] == 'I'){
                if (cstr[i + 1] == 'V') {
                    res += 4; i++;
                }
                else if (cstr[i + 1] == 'X'){
                    res += 9; i++;
                }    
                else res += 1;
            }else if (cstr[i] == 'V'){
                res += 5;
            }else if (cstr[i] == 'X'){
                if (cstr[i + 1] == 'L') {
                    res += 40; i++;
                }
                else if (cstr[i + 1] == 'C'){
                    res += 90; i++;
                }
                else res += 10;
            }else if (cstr[i] == 'L'){
                res += 50;
            }else if (cstr[i] == 'C'){
                if (cstr[i + 1] == 'D') {
                    res += 400; i++;
                }
                else if (cstr[i + 1] == 'M') {
                    res += 900; i++;
                }
                else res += 100;
            }else if (cstr[i] == 'D'){
                res += 500;
            }else if (cstr[i] == 'M'){
                res += 1000;
            }
        }

        if (i <= length){
            if (cstr[length] == 'I')    res += 1;
            else if (cstr[length] == 'V')   res += 5;
            else if (cstr[length] == 'X')   res += 10;
            else if (cstr[length] == 'L')   res += 50;
            else if (cstr[length] == 'C')   res += 100;
            else if (cstr[length] == 'D')   res += 500;
            else if (cstr[length] == 'M')   res += 1000;
        }

        return res;
    }
}