/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
 

Constraints:
1 <= n <= 8
*/

class Solution {
public:
    vector<string> result;
    
    void helper(string str, 
                int numOfPairs, 
                int countOpening, 
                int countClosing){
        if ((str.length() == 2 * numOfPairs) && countOpening == countClosing){
            result.push_back(str);
            return;
        }
        
        if (countOpening < numOfPairs){
            helper(str + "(", numOfPairs, countOpening + 1, countClosing);
        }
        if (countClosing < countOpening){
            helper(str + ")", numOfPairs, countOpening, countClosing + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        
        helper("", n, 0, 0);        
        return result;
    }
};