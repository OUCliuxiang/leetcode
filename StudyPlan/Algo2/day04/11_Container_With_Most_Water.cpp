/**
 * Given n non-negative integers a1, a2, ..., an , where each represents a 
 * point at coordinate (i, ai). n vertical lines are drawn such that the 
 * two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, 
 * which, together with the x-axis forms a container, such that the container 
 * contains the most water.             
 * Notice that you may not slant the container.           
 * 
 * Example 1:           
 * Input: height = [1,8,6,2,5,4,8,3,7]            
 * Output: 49           
 * Explanation: The above vertical lines are represented by array [1,8,6,
 * 2,5,4,8,3,7]. In this case, the max area of water (blue section) the con-
 * tainer can contain is 49.          
 * 
 * Example 2:            
 * Input: height = [1,1]            
 * Output: 1           
 * 
 * Example 3:          
 * Input: height = [4,3,2,1,4]            
 * Output: 16           
 * 
 * Example 4:         
 * Input: height = [1,2,1]           
 * Output: 2          
 * 
 * Constraints:            
 * * n == height.length           
 * * 2 <= n <= 105           
 * * 0 <= height[i] <= 104
 */       
class Solution {
public:
    int maxArea_TLE(vector<int>& height) {
        int most = 0;
        for(int i = 0; i < height.size(); i++)
            for(int j = i+1; j < height.size(); j++)
                most = max(most, (j-i) * min(height[i], heights[j]));            
    return most;
    }

    int maxArea_discuss(vector<int>& height) {
        int most = 0, front = 0, back = height.size()-1;
        while(front < back){
            int h = min(height[front], height[back]);
            most = max(most, ( back - front) * h);
            while(front < back && height[front] <= h) front++;
            while(front < back && height[ back] <= h) back --;
        }
        return most;
    }
}; 