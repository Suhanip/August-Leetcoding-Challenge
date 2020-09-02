/*PROBLEM STATEMENT:
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

*/

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(char c :s){
            //'A' = 0
            int d = c-'A'+1; 
            result = result*26 + d;
        }
     return result;  
    }
};
