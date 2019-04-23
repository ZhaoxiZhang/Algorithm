struct Node{
	double len,speed;
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        Node node[n + 5];
        for (int i = 0;i < n;i++){
        	node[i].len = target - position[i];
        	node[i].speed = speed[i];
        }
        sort(node,node + n,cmp);
        int index = 0;
        int res = 0;
        for (;;){
        	int pos = index + 1;
        	while (pos < n && node[pos].len / node[pos].speed
        			<= node[index].len / node[index].speed){
        		pos++;
        	}
            if (index >= n){
                break;
            }
        	res++;
        	index = pos;
            
        }
        return res;
    }
    
    static bool cmp(Node a,Node b){
    	return a.len < b.len;
    }
};