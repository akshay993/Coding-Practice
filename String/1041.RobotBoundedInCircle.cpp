/*
1041. Robot Bounded In Circle

On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

Example 1:
Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.

Example 2:
Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.

Example 3:
Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ... 

Constraints:
1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'.
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        char curDir = 'N';
        int vertical = 0, horizontal = 0;
        int n = instructions.length();
        
        for (int i = 0; i < n; i++){
            if (instructions[i] == 'G') {
                if (curDir == 'N') {
                    vertical++;
                } else if (curDir == 'S') {
                    vertical--;
                } else if (curDir == 'E') {
                    horizontal++;
                } else if (curDir == 'W') {
                    horizontal--;
                }
            } else {
                
                if (curDir == 'N' ) {
                    if (instructions[i] == 'L') {
                        curDir = 'W';
                    } else {
                        curDir = 'E';
                    }
                } else if (curDir == 'S') {
                    if (instructions[i] == 'L') {
                        curDir = 'E';
                    } else {
                        curDir = 'W';
                    }
                } else if (curDir == 'E') {
                    if (instructions[i] == 'L') {
                        curDir = 'N';
                    } else {
                        curDir = 'S';
                    }
                } else if (curDir == 'W'){
                    if (instructions[i] == 'L') {
                        curDir = 'S';
                    } else {
                        curDir = 'N';
                    }
                }                
            }            
        }
        
        if ((horizontal == 0 && vertical == 0) || (curDir != 'N')){
            return true;
        } 
        
        return false;
    }
};