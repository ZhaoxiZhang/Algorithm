/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    public:
        static bool cmp(Interval x, Interval y){
            return x.start < y.start;
        }

        int eraseOverlapIntervals(vector<Interval>& intervals) {
            if (0 == intervals.size())  return 0;
            sort(intervals.begin(), intervals.end(), cmp);
            int ed = intervals[0].end;
            int res = 0;
            for (int i = 1; i < intervals.size(); i++){
                if (intervals[i].end <= ed){
                    ed = intervals[i].end;
                    res++;
                }else if (intervals[i].start < ed && intervals[i].end > ed){
                    res++;
                }else{
                    ed = intervals[i].end;
                }
            }
            return res;
        }
};
