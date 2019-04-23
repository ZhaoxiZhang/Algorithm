class Solution {
public:
    int mp[26] = {0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0};

    const int SHIFT = 5;
    const int MASK = 0x1F;
    void bitSet(int i, int a[]){    a[i >> SHIFT] |= (1 << (i & MASK)); }
    int bitTest(int i, int a[]){    return a[i >> SHIFT] & (1 << (i & MASK)); }

    vector<string> findRepeatedDnaSequences(string s) {
        set<string>st;
        int once[1 + 1024 * 1024 * 2 / 32] = {0};

        int size = s.size();
        for (int i = 0; i < size - 9; i++){
            int value = 0;
            for (int j = i; j < i + 10; j++){
                value <<= 2;
                value |= (mp[s[j] - 'A']);
            }
            if (bitTest(value, once)){
                st.insert(s.substr(i, 10));
            }else{
                bitSet(value, once);
            }
        }

        return vector<string>(st.begin(), st.end());
    }
};