/** 
 * You are climbing a staircase. It takes n steps to reach the top.      
 * Each time you can either climb 1 or 2 steps. In how many distinct 
 * ways can you climb to the top?             
 * 
 * Example 1:       
 * Input: n = 2       
 * Output: 2         
 * Explanation: There are two ways to climb to the top.       
 * 1. 1 step + 1 step           
 * 2. 2 steps         
 * 
 * Example 2:       
 * Input: n = 3        
 * Output: 3          
 * Explanation: There are three ways to climb to the top.       
 * 1. 1 step + 1 step + 1 step       
 * 2. 1 step + 2 steps        
 * 3. 2 steps + 1 step           
 * 
 * Constraints:      
 *  1 <= n <= 45      
 */

class Solution {
public:
    int climbStairs_TLE(int n) {
        if (n == 0 || n == 1) return 1;
        int count  = 0;
        helper(0, n, count);
        return count;
    }

    int climbStairs_DP(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int step[n];
        step[0] = 1;
        step[1] = 2;
        for (int i = 2; i < n; i++)
            step[i] = step[i-1] + step[i-2];
        return step[n-1];
    }
private:
    void helper(int curr, int n, int& count){
        if (curr == n){
            count ++;
            return;
        }
        helper(curr+1, n, count);
        if (curr + 2 <= n)
            helper(curr+2, n, count);  
    }


};  