/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public int eraseOverlapIntervals(Interval[] intervals) {
       if (null == intervals || 0 == intervals.length)  return 0;
       Arrays.sort(intervals, Comparator.comparingInt(o -> o.start));
       int ed = intervals[0].end;
       int res = 0;
       for (int i = 1; i < intervals.length; i++){
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
}