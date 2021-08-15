/*

1423. Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.


Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length

*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int totalScore = 0;
        int n = cardPoints.size();
        
        for (int i = 0; i < n; i++){
                totalScore = totalScore + cardPoints[i];
        }            
        
        if (k == n){            
            return totalScore;
        }
        
        int startIndex = 0;
        int currentSubarrayScore = 0;
        int minSubarrayScore = totalScore;
        int requiredSubarrayLength = n - k;
        
        for (int i = 0; i < n; i++){
            
            currentSubarrayScore += cardPoints[i];
            int presentSubarrayLength = i - startIndex + 1;
            
            if (presentSubarrayLength == requiredSubarrayLength){
                
                minSubarrayScore = min(minSubarrayScore, currentSubarrayScore);
                
                currentSubarrayScore -= cardPoints[startIndex];
                startIndex += 1;                
            }            
        }
        
        return totalScore - minSubarrayScore;       
    }
};