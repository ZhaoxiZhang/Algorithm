#include<bits/stdc++.h>
using namespace std;
const int maxn = 260;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	string str;
    int n,a[5] = {0};
    cin >> n >> str;
    if (n % 4)  cout << "===" << endl;
    else
    {
        int cnt = 0;
        int len = str.size();
        a[0] = a[1] = a[2] = a[3] = n/4;
        for (int i = 0;i < len;i++)
        {
            if (str[i] == 'A')  a[0]--;
            if (str[i] == 'C')  a[1]--;
            if (str[i] == 'G')  a[2]--;
            if (str[i] == 'T')  a[3]--;
            if (str[i] == '?')  cnt++;
        }
        if (a[0] < 0 || a[1] < 0 || a[2] < 0 || a[3] < 0)   cout << "===" << endl;
        else
        {
            for (int i = 0;i < len;i++)
            {
                if (str[i] == '?')
                {
                    if (a[0])   str[i] = 'A',a[0]--;
                    else if (a[1])  str[i] = 'C',a[1]--;
                    else if (a[2])  str[i] = 'G',a[2]--;
                    else    str[i] = 'T',a[3]--;
                }
            }
            cout << str << endl;
        }
    }
    return 0;
}
