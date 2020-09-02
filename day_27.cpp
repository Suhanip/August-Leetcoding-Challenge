/*PROBLEM STATEMENT
Given an array of intervals where intervals[i] = [starti, endi]. For each interval i, check if there exists an interval j where startj >= endi, which can be called that interval j is on the right of interval i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "on the right of" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you should return the stored value of each interval as an array.

NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

Example 1:
Input: intervals = [[1,2]]
Output: [-1]
Explanation: There is only one interval in the collection, so it outputs -1.

Example 2:
Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.

*/
class Solution {
    int binary_search(vector<pair<pair<int, int>,int>>& sorted, int x){
        int n = sorted.size();
        if(sorted[n-1].first.first < x) return -1;
        
        int l = 0,r = n-1;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(sorted[mid].first.first >=x) r =mid-1;
            else l =mid+1;
        }
        return sorted[l].second;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<pair<int, int>,int>> sorted;
        int n = intervals.size();
        int i=0,j=0;
        for(i = 0;i<n;i++)
            sorted.push_back({{intervals[i][0], intervals[i][1]},i});
        
        sort(sorted.begin(),sorted.end());
        
            vector<int> result(n,-1);
            for(i = 0;i<n;i++){
                result[i] = binary_search(sorted,intervals[i][1]);
            }
        return result;
    }
};
