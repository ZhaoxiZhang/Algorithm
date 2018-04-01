#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //109
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};

int main(){
    int x;
    cin >> x;
    Solution solution;
    cout << solution.isPalindrome(x) << endl;
    return 0;
}
