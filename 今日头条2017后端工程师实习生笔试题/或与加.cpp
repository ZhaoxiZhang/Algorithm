#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x,k;
    cin >> x >> k;
    long long res = 0;
    long long tmp = 1;
    while (x){
        if ((!(x & 1))){
            if (k & 1){
                res |= tmp;
            }
            k >>= 1;
        }
        x >>= 1;
        tmp <<= 1;
    }
    while (k){
        if (k & 1){
            res |= tmp;
        }
        k >>= 1;
        tmp <<= 1;
    }
    cout << res << endl;
    return 0;
}
