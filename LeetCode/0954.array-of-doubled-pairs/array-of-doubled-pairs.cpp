class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        int size = A.size();
        if (size == 0)  return true;
        sort(A.begin(), A.end());
        map<int,int>mp;
        bool hasNegavite = false;
        int pos = 0;
        for (int i = 0; i < size; i++){
            mp[A[i]]++;
            
            if(A[i] < 0){
                hasNegavite = true;
                pos = i;
            }
        }

        if (hasNegavite){
            if (!(pos & 1)) return false;
            for (int i = pos; i >= 0; i--){
                if (mp[A[i]] != 0) {
                    if (mp[2 * A[i]] != 0){
                        mp[A[i]]--;
                        mp[2 * A[i]]--;
                    }else   return false;
                }
            }
            for (int i = pos + 1; i < size; i++){
                if (mp[A[i]] != 0){
                    if (mp[2 * A[i]] != 0){
                        mp[A[i]]--;
                        mp[2 * A[i]]--;
                    }else return false;
                }
            }

        }else{
            for (int i = 0; i < size; i++){
                if (mp[A[i]] != 0){
                    if (mp[2 * A[i]] != 0){
                        mp[A[i]]--;
                        mp[2 * A[i]]--;
                    }else   return false;
                }
            }
        }

        return true;
    }
};