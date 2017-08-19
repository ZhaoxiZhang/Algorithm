#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //6ms
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x && y){
            if ((x & 1) != (y & 1)) res++;
            x >>= 1;
            y >>= 1;
        }
        while (x){
            if (x & 1)	res++;
            x >>= 1;
        }
        while (y){
            if (y & 1)	res++;
            y >>= 1;
        }
        return res;
    }

    //3ms
    int hammingDistance(int x,int y){
        x ^= y;
        y = 0;
        while (x){
            y += (x & 1);
            x >>= 1;
        }
        return y;
    }
};


int main(){
    int x,y;
    cin >> x >> y;
    Solution solution;
    cout << solution.hammingDistance(x,y) << endl;
    return 0;
}
