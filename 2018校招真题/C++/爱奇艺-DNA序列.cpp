/*
 * Description: 牛牛又从生物科研工作者那里获得一个任务,这次牛牛需要帮助科研工作者从DNA序列s中找出
 * 最短没有出现在DNA序列s中的DNA片段的长度。
 * 例如:s = AGGTCTA
 * 序列中包含了所有长度为1的('A','C','G','T')片段,但是长度为2的没有全部包含,例如序列中不包含"AA",所以输出2。
 * Input: 输入包括一个字符串s,字符串长度length(1 ≤ length ≤ 2000),其中只包含'A','C','G','T'这四种字符。
 * Output: 输出一个正整数,即最短没有出现在DNA序列s中的DNA片段的长度。
 * SampleInput:
 * AGGTCTA
 * SampleOutput:
 * 2
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int size = str.size();
    for (int i = 1; i <= size; i++){
        set<string>s;
        for (int j = 0; j <= size - i; j++){
            s.insert(str.substr(j, i));
        }
        if (s.size() != pow(4, i)){
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
