#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
    string str;
    while (getline(cin,str))
    {
        int len = str.size();
        int cnt = 0;
        bool flag = true;
        for (int i = 0; i < len; i++)
        {
            if (str[i] != str[i + 1])
            {
                if (flag)
                {
                    cout << "1";
                    flag = false;
                }
                if (str[i] == '1')
                {
                    cout <<"11";
                }
                else
                {
                    cout << str[i];
                }
                if (str[i + 1] == str[i + 2] || i == len - 1)
                {
                    cout << "1";
                    flag = true;
                }
            }
            else if (str[i] == str[i + 1])
            {
                cnt++;
                if (cnt == 8)
                {
                    cout << "9" << str[i];
                    cnt = 0;
                    i++;
                }
                else if (str[i + 1] !=  str[i + 2])
                {
                    cout << cnt + 1 << str[i];
                    i++;
                    cnt = 0;
                }
            }
        }
        cout << endl;
    }
    return 0;
}

