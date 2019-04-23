class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int size = points.size();
        if (0 == size)  return 0;
        sort(points.begin(), points.end());
        int res = 1;
        int start = points[0].first, end = points[0].second;
        for (int i = 1; i < size; i++){
            if ((points[i].first >= start && points[i].second <= end)
                    || (points[i].first <= end && points[i].second >= end)){
                start = max(points[i].first, start);
                end = min(points[i].second, end);
            }else{
                res++;
                start = points[i].first;
                end = points[i].second;
            }
        }
        return res;
    }

};