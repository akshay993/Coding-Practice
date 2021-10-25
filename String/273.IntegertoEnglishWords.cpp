/*
273. Integer to English Words

Convert a non-negative integer num to its English words representation.

Example 1:
Input: num = 123
Output: "One Hundred Twenty Three"

Constraints:
0 <= num <= 231 - 1
*/
class Solution {
private:
    unordered_map<int, string> ones;
    unordered_map<int, string> tens;
    
    string numberToWord(int n){
        
        if (n >= 1000000000){
            return numberToWord(n / 1000000000) + " Billion" + numberToWord(n % 1000000000);
        } else if (n >= 1000000){
            return numberToWord(n / 1000000) + " Million" + numberToWord(n % 1000000);
        } else if (n >= 1000){
            return numberToWord(n / 1000) + " Thousand" + numberToWord(n % 1000);
        } else if (n >= 100){
            return numberToWord(n / 100) + " Hundred" + numberToWord(n % 100);
        } else if (n >= 20){
            return " " + tens[n / 10] + numberToWord(n % 10);
        } else if (n >= 1){
            return " " + ones[n];
        }
        return "";
    }
    
public:
    
    Solution(){
        ones = {{1, "One"},{2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"},{7, "Seven"},{8, "Eight"},{9, "Nine"}, {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}};
        
        tens = {{2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}};
        
    }
    
    string numberToWords(int n) {
        
        if (n == 0){
            return "Zero";
        }
        
        return numberToWord(n).substr(1);
    }    
};