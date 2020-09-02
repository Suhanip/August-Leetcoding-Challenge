/*PROBLEM STATEMENT:
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.

for example:
Input: "abccccdd"

Output: 7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/

class Solution {
public:
    int longestPalindrome(string s) {
      unordered_map<char, int> mp;
      for (auto i : s)
         mp[i]++;
      int ma = 0, c = 0, ans = 0;
      for (auto i : mp) {
         if ((i.second) % 2 == 1)
            ma++;
         c += i.second;
      }
      if (ma > 0)
         ma--;
      ans = c - ma;
      return ans;
   }
};
