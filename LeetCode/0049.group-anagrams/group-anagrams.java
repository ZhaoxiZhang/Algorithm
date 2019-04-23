class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<HashableArray, List<String>>hashMap = new HashMap<>();
        for (String str : strs){
            HashableArray hashableArray = new HashableArray();
            for (char ch : str.toCharArray()){
                hashableArray.val[ch - 'a']++;
            }
            if (!hashMap.containsKey(hashableArray))    hashMap.put(hashableArray, new ArrayList<>());
            hashMap.get(hashableArray).add(str);
        }
        return new ArrayList<>(hashMap.values());
    }
}

class HashableArray{
    int[] val = new int[26];

    @Override
    public boolean equals(Object obj) {
        return Arrays.equals(this.val, ((HashableArray)obj).val);
    }

    @Override
    public int hashCode() {
        return Arrays.hashCode(val);
    }
}