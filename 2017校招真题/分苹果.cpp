#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];

int main(){
    int n,res = 0;
    double sum = 0,avg = 0;
    //bool even = false,odd = false;
    bool haseven = false,hasodd = false;
    scanf("%d",&n);
    for (int i = 0;i < n;i++) {
        scanf("%d",&a[i]);
        sum += a[i];
        if (a[i] & 1)   hasodd = true;
        else    haseven = true;
    }
    avg = sum / n;
    if ((avg - (int)(avg) != 0) || ((((int)avg) & 1) && haseven) || (!((int)avg & 1) && hasodd)){
        printf("-1\n");
    } else{
        avg = (int)avg;
        for (int i = 0;i < n;i++){
            if (a[i] > avg){
                res += (a[i] - avg);
            }
        }
        printf("%d\n",res / 2);
    }
    return 0;
}
