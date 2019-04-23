class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int left[seats.size()];
        int right[seats.size()];
        int r = 2 * seats.size() - 1,l = -r;
        for (int i = 0;i < seats.size();i++){
        	if (!seats[i]){
        		left[i] = l;
        	}else{
        		left[i] = i;
        		l = i;
        	}
        }
        
        for (int i = seats.size() - 1;i >= 0;i--){
        	if (!seats[i]){
        		right[i] = r;
        	}else{
        		right[i] = i;
        		r = i;
        	}
        }
        int res = 0;
        for (int i = 0;i < seats.size();i++){
        	if (!seats[i]){
        		res = max(res,min(i - left[i],right[i] - i));
        	}
        }
        return res;
    }
};