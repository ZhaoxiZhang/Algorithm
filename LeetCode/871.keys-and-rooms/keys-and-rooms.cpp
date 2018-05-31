class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool vis[1005];
        memset(vis,false,sizeof(vis));
        queue<int>que;
        que.push(0);
        vis[0] = true;
        while (!que.empty()){
        	int index = que.front();
            que.pop();
        	for (int val : rooms[index]){
        		if (!vis[val]){
        			que.push(val);
                    
        			vis[val] = true;
        		}
        	}
        }
        for (int i = 0;i < rooms.size();i++){
        	if (!vis[i])    return false;
        }
        return true;
    }
};