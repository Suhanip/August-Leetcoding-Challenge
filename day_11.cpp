/*PROBLEM STATEMENT:

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

for example:

Input: citations = [3,0,6,1,5]
Output: 3 
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end()); 
        int l = 0, r = n-1;
	 /*Time Complexity is O(n) and starts from the beginning
        int i = 0;
        while(i<n){
            if(citations[i] < n-i)
                i++;
            else
                break;
        }
        return n-i;*/
        /*Time Complexity is O(n) starts from the end
        int i = n-1;
        while(i>=0){
            if(citations[i] < n-i) break;
            i--;
        }
        return n-i-1;*/
        
        //Time Complexity is O(nlogn)
        while(l <= r){
            int mid = l+(r-l)/2;
            if(citations[mid] < n-mid)
                l = mid+1;
            else
                r = mid -1;
        }
        return n-l;
    }
};
