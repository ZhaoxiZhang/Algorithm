#include<bits/stdc++.h>
using namespace std;
const int maxn = 50005;
char s[maxn];
int stk[maxn];

int main(){
    int cnt,top = -1;
    scanf("%s %d",s,&cnt);
    int len = strlen(s);
    for (int i = 0;i < len - 1;i++){
        if (s[i] >= s[i + 1] || !cnt){
            stk[++top] = s[i] - '0';
        }else if (cnt && s[i] < s[i + 1]){
            cnt--;
            while (cnt && top >= 0 && stk[top] < s[i + 1] - '0'){
                top--;
                cnt--;
            }
        }
    }
    stk[++top] = s[len - 1] - '0';
    while (cnt){
        cnt--;
        top--;
    }
    for (int i = 0;i <= top;i++){
        printf("%d",stk[i]);
    }
    printf("\n");
    return 0;
}
