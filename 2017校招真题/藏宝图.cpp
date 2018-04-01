#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
char str[maxn],des[maxn];

int main(){
    scanf("%s %s",str,des);
    int slen = strlen(str);
    int dlen = strlen(des);
    int j = 0;
    for (int i = 0;i < slen;i++){
        if (str[i] == des[j]){
            j++;
        }
        if (j == dlen){
            printf("Yes\n");
            break;
        }
    }
    if (j != dlen)  printf("No\n");
    return 0;
}
