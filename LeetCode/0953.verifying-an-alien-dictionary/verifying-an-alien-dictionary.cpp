class Solution {
private:
    int val[30] = {0};
public:

    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++){
            val[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++){
            string a = words[i - 1];
            string b = words[i];
            int asize = a.size();
            int bsize = b.size();
            int size = asize < bsize ? asize : bsize;
            bool undefine = true;
            for (int j = 0; j < size; j++){
                if (val[a[j] - 'a'] == val[b[j] - 'a']) continue;
                if (val[a[j] - 'a'] < val[b[j] - 'a']){
                    undefine = false;
                    break;
                } 
                if (val[a[j] - 'a'] > val[b[j] - 'a'])  return false;
            }
            if (undefine && asize > bsize)  return false;
        }
        return true;
    }
};