/*
680. Valid Palindrome II

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true

Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

Example 3:
Input: s = "abc"
Output: false
 
Constraints:
1 <= s.length <= 105
s consists of lowercase English letters.

*/

class Solution {
public:
    bool validPalindrome(string s) {
        
        int n = s.length();        
        if (n <= 2){
            return true;
        }
        
        for (int i = 0; i < n / 2; i++){
            int left = i, right = n - i - 1;
            if (s[left] != s[right]){
                
                // delete left char and check for palindrome
                if (validSubPalindrome(s, left + 1, right)){
                    return true;
                }
                
                // delete right char and check for palindrome
                if (validSubPalindrome(s, left, right - 1)){
                    return true;
                }
                
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool validSubPalindrome(string s, int lo, int hi){
        int n = hi - lo + 1;
        for (int i = 0; i < n / 2; i++){
            int left = lo + i, right = hi - i; 
            if (s[left] != s[right]){
                return false;
            }
        }
        
        return true;
    }
};