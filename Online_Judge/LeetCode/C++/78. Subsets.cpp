#include<bits/stdc++.h>
using namespace  std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort (S.begin(), S.end());
        int elem_num = S.size();
        int subset_num = pow (2, elem_num);
        vector<vector<int> > subset_set (subset_num, vector<int>());
        for (int i = 0; i < elem_num; i++)
            for (int j = 0; j < subset_num; j++)
                if ((j >> i) & 1)
                    subset_set[j].push_back (S[i]);
        for (unsigned int i = 0;i < subset_set.size();i++){
            for (unsigned int j = 0;j < subset_set[i].size();j++){
                cout << subset_set[i][j] << " ";
            }
            cout << endl;
        }
        return subset_set;
    }
};


int main(){
	freopen("input.txt","r",stdin);
    int n,tmp;
    vector<int>S;
    cin >> n;
    for (int i = 0; i< n;i++)   cin >> tmp,S.push_back(tmp);
    Solution solution;
    vector<vector<int> > res = solution.subsets(S);
//    for (unsigned int i = 0;i < res.size();i++){
//    	cout << res[i] << endl;
//    	cout << i << endl;
//    }
	return 0;
}
