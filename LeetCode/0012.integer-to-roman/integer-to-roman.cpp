class Solution {
public:
    string intToRoman(int num) {
        string res;
        int quotient;

        //case num > 1000:
        quotient = num / 1000;
        num = num - 1000 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "M";
        //case 900:
        quotient = num / 900;
        num = num - 900 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "CM";
        //case 500:
        quotient = num / 500;
        num -= 500 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "D";
        //case 400:
        quotient = num / 400;
        num -= 400 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "CD";
        //case 100:
        quotient = num / 100;
        num -= 100 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "C";
        //case 90:
        quotient = num / 90;
        num -= 90 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "XC";
        //case 50:
        quotient = num / 50;
        num -= 50 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "L";
        //case 40:
        quotient = num / 40;
        num -= 40 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "XL";
        //case 10:
        quotient = num / 10;
        num -= 10 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "X";
        //case 9:
        quotient = num / 9;
        num -= 9 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "IX";
        //case 5:
        quotient = num / 5;
        num -= 5 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "V";
        //case 4:
        quotient = num / 4;
        num -= 4 * quotient;
        for (int i = 0; i < quotient; i++)
            res += "IV";
        //case 1:
        for (int i = 0; i < num; i++)
            res += "I";

        return res;
    }
};