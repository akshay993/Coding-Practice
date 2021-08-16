/*
735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        
        for (int i=0; i<asteroids.size(); i++){
            
            int ast = asteroids[i];
            bool collision = false;
            while (!st.empty() && ast < 0 && st.top() > 0 && !collision){
                
                if (st.top() < -ast){
                    st.pop();
                    continue;
                }
                else if (st.top() == -ast){
                    st.pop();                    
                }            
                collision = true;                    
                break;
            }
            
            if (!collision){                
                st.push(ast);
            }
        }
        
        vector<int> result(st.size());
        
        for (int i= st.size()-1; i>=0; i--){
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};