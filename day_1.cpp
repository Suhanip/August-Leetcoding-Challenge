/*PROBLEM STATEMENT:
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    *All letters in this word are capitals, like "USA".
    *All letters in this word are not capitals, like "leetcode".
    *Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

for example:
	1. Input: 'USA'				(All are capital,returns true)
	   Output: 'true'
	1. Input: 'USa'				(Only first 2letters are capital others are lower,returns false)
	   Output: 'false'
	1. Input: 'Ball'			(First is capital others are small,returns true)
	   Output: 'true'
	1. Input: 'BalL'			(First and last are capital,returns false)
	   Output: 'false'	 
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()<2) return true; //either word is empty or have length 1
        if(isupper(word[0]) && isupper(word[1])){//or we can use word[0]>='A' && word[0]<='Z'
            for(int i=2;i<word.length();i++){ //third till end should be uppercase
                if(islower(word[i])) return false;
            }
        }else {
           for(int i=1;i<word.length();i++){ //second till end should be lowercase
                if(isupper(word[i])) return false;
            } 
        }
        return true;
    }
};
