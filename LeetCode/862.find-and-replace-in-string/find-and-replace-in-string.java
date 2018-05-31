import javafx.util.Pair;
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        StringBuilder stringBuilder = new StringBuilder(S);
        List<Pair<Integer,Integer>>list = new ArrayList<>(indexes.length);
        for (int i = 0;i < indexes.length;i++){
            list.add(new Pair<>(indexes[i],i));
        }
        list.sort(new Comparator<Pair<Integer, Integer>>() {
            @Override
            public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
                return o1.getKey() - o2.getKey();
            }
        });
        int pos = 0;
        int len = list.size();
        for (int i = 0;i < len;i++){
            int key = list.get(i).getKey();
            int value = list.get(i).getValue();
            if (sources[value].equals(S.substring(key,key + sources[value].length()))){
                // System.out.println("key = " + key + " pos = " + pos);
                // System.out.println((key + pos) + " " + (key + pos + sources[value].length()) + " " + targets[value]);
                stringBuilder.replace(key + pos,key + pos + sources[value].length(),targets[value]);
                pos += targets[value].length() - sources[value].length();
                //System.out.println(stringBuilder.toString() + " pos = " + pos);
            }
        }
        return stringBuilder.toString();
    }
}