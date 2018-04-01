#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,opt;
    long long len,lenmax = 0,lensum = 0;

    multiset<long long>mset;
    multiset<long long>::iterator it;
    scanf("%d",&n);
    while (n--){
        cin >> opt >>len;
        if (opt == 1){
            mset.insert(len);
            lensum += len;
            lenmax = max(lenmax,len);
            if (lensum - lenmax <= lenmax){
                printf("No\n");
            }else{
                printf("Yes\n");
            }
        }else{
            for (it = mset.begin(); it != mset.end();it++){
                if (*it == len){
                    mset.erase(it);
                    break;
                }
            }
            lensum -= len;
            lenmax = *(mset.rbegin());
            if (lensum - lenmax <= lenmax){
                printf("No\n");
            }else{
                printf("Yes\n");
            }
        }
    }
    return 0;
}
