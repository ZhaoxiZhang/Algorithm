#include<bits/stdc++.h>
using namespace std;
stack<int>stk;
char opt[10];

int main(){
	int n,num,res = 0,cur = 1;
	scanf("%d",&n);
	n <<= 1;
	for (int i = 0;i < n;i++){
		scanf("%s",opt);
		if (opt[0] == 'a'){
			scanf("%d",&num);
			stk.push(num);
		}else{
			if (!stk.empty()){
				if (stk.top() == cur){
					stk.pop();
				}else{
					res++;
					while (!stk.empty())	stk.pop();
				}
			}
			cur++;
		}
	}
	printf("%d\n",res);
	return 0;
}
