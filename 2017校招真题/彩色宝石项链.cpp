#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
char str[maxn];
int exits[10];

struct Node{
    int index;
    char val;
};

int main(){
    while (~scanf("%s",str)){
        int size = 0,index = 0;
        Node node,lastnode;
        queue<Node>que[5];
        queue<Node>q;
        int len = strlen(str);
        for (int i = 0;i < len;i++){
            index = str[i] - 'A';
            if (index < 5){
                node.index = i;
                node.val = str[i];
                que[index].push(node);
            }
        }
        size = que[0].size() + que[1].size() + que[2].size() + que[3].size() + que[4].size();
        if (size < 5){
            printf("0\n");
        }else{
            int pos,cnt;
            for (int i = 0;i < len;i++){
                index = str[i] - 'A';
                if (!exits[index]){
                    node.index = i;
                    node.val = str[i];
                    q.push(node);
                    exits[index] = 1;
                }
                if (q.size() == 5){
                    lastnode.val = str[i];
                    lastnode.index = i;
                    pos = i;
                    break;
                }
            }
            for (int i = pos + 1;i < len;i++){
                node = q
            }
        }
    }
}
