class Solution {
public:
    void replaceSpace(char *str,int length) {
        int i = 0,blank = 0;
        while (str[i] != '\0'){
            if (str[i++] == ' '){
                blank++;
            }
        }
        int originLength = i;
        int newLength = originLength + blank * 2;
        while (originLength >= 0 && originLength <= newLength){
            if (str[originLength] == ' '){
                str[newLength--] = '0';
                str[newLength--] = '2';
                str[newLength--] = '%';
                originLength--;
            }else{
                str[newLength--] = str[originLength--];
            }
        }
    }
};