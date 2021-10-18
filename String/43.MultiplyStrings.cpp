/*
43. Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
 
Constraints:
1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n = num1.length();
        int m = num2.length();
        vector<int> vals(n + m, 0);
        string result;
        
        for (int i = m - 1; i >=0; i--){            
            int n1 = num2[i] - '0';            
            for (int j = n - 1; j >= 0; j--){                
                int n2 = num1[j] - '0';
                int sum = n1 * n2 + vals[i + j + 1];
                vals[i + j + 1] = (sum % 10);
                vals[i + j] = vals[i + j] + (sum / 10);                
            }
        }
        
        for (int i = 0; i < vals.size(); i++){
            // Handeling leading zeros
            if (result.length() > 0 || vals[i] != 0){
                result += to_string(vals[i]);
            }
        }
        
        if (result.length() == 0){
            return "0";
        }
        
        return result;
    }
};