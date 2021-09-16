/*
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    void generate(string digits, unordered_map<char, vector<char>>& dialPad, int pos, string str, vector<string>& ans){
        
        if (str.length() == digits.length()){
            ans.push_back(str);
            return;
        }
        
        vector<char> letters = dialPad[digits[pos]];
        for (int i = 0; i < letters.size(); i++){
            generate(digits, dialPad, pos + 1, str + letters[i], ans);
        }
    }
    
    void populateDialPad(unordered_map<char, vector<char>>& dialPad){
        dialPad['2'] = vector<char>{'a', 'b', 'c'};
        dialPad['3'] = vector<char>{'d', 'e', 'f'};
        dialPad['4'] = vector<char>{'g', 'h', 'i'};
        dialPad['5'] = vector<char>{'j', 'k', 'l'};
        dialPad['6'] = vector<char>{'m', 'n', 'o'};
        dialPad['7'] = vector<char>{'p', 'q', 'r', 's'};
        dialPad['8'] = vector<char>{'t', 'u', 'v'};
        dialPad['9'] = vector<char>{'w', 'x', 'y', 'z'};
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if (digits.length() == 0){
            return ans;
        }
        
        unordered_map<char, vector<char>> dialPad;
        populateDialPad(dialPad);
        
        generate(digits, dialPad, 0, "", ans);        
        return ans;
    }
};