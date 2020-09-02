/*PROBLEM STATEMENT:
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

for example:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
*/


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return 0;
        sort(intervals.begin(),intervals.end(), [](const vector<int>& a,const vector<int>& b){
           return a[0] < b[0]; 
        });
        int count = 0, last_included = 0;
        for(int i= 1;i<intervals.size();++i){
            if(intervals[i][0] < intervals[last_included][1]){
                count++;
                if(intervals[i][1] < intervals[last_included][1])
                    last_included = i;
            } else
                last_included = i; 
        }
        return count;
    }
};
