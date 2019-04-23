/*
 * Description: 牛牛想尝试一些新的料理，每个料理需要一些不同的材料，问完成所有的料理需要准备多少种不同的材料。
 * Input: 每个输入包含 1 个测试用例。每个测试用例的第 i 行，表示完成第 i 件料理需要哪些材料，
 * 各个材料用空格隔开，输入只包含大写英文字母和空格，输入文件不超过 50 行，每一行不超过 50 个字符。
 * Output: 输出一行一个数字表示完成所有料理需要多少种不同的材料。
 * SampleInput:
 * BUTTER FLOUR
 * HONEY FLOUR EGG
 * Sample Output:
 * 4
 */

#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
char str[maxn];
set<string>s;

int main(){
    //freopen("input.txt","r",stdin);
    while (~scanf("%s",str)){
        s.insert(str);
    }
    cout << s.size() << endl;
    return 0;
}
