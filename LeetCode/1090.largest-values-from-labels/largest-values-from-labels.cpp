static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

struct Node {
    int value, label;

    bool operator < (const Node &node)const{
        return value > node.value;
    }
};

class Solution {
public:

    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit) {
        int size = values.size();
        Node node[size + 5];
        int sum = 0;
        map<int, int>mp;
        map<int, int>::iterator it;
        for (int i = 0; i < size; i++) {
            node[i].value = values[i];
            node[i].label = labels[i];
        }
        sort(node, node + size);
        for (int i = 0; i < size && num_wanted; i++) {
            if (mp.find(node[i].label) != mp.end()) {
                if (mp[node[i].label] < use_limit) {
                    sum += node[i].value;
                    mp[node[i].label]++;
                    num_wanted--;
                }
            } else {
                mp[node[i].label] = 1;
                sum += node[i].value;
                num_wanted--;
            }
        }
        return sum;
    }
};