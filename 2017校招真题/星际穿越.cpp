#include<bits/stdc++.h>
using namespace std;

int main(){
    double h;
    cin >> h;
    double x = (-1 + sqrt(1 + 4 * h)) / 2;
    long long res = x + 1;
    if (res + res * res <= h){
        cout << res << endl;
    }else{
        cout << (long long)x << endl;
    }
    return 0;
}
