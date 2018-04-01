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
