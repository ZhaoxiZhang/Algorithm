/*
 * Description: 数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。
 * Input: 输入数据有多组，每组占一行，由两个整数n（n < 10000）和m(m < 1000)组成，n和m的含义如前所述。
 * Output: 对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。
 * SampleInput:
 * 81 4
 * 2 2
 * SampleOutput:
 * 94.73
 * 3.41
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        double res = n,tmp = n;
        for (int i = 1;i < m;i++){
            tmp = sqrt(tmp);
            res += tmp;
        }
        printf("%.2f\n",res);
    }
    return 0;
}
