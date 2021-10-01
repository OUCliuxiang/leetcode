/**
 * You are a professional robber planning to rob houses along a street. 
 * Each house has a certain amount of money stashed, the only constraint 
 * stopping you from robbing each of them is that adjacent houses have 
 * security systems connected and it will automatically contact the 
 * police if two adjacent houses were broken into on the same night.        
 * 
 * Given an integer array nums representing the amount of money of each 
 * house, return the maximum amount of money you can rob tonight without 
 * alerting the police.         
 * 
 * Example 1:           
 * Input: nums = [1,2,3,1]           
 * Output: 4            
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.           
 * 
 * Example 2:          
 * Input: nums = [2,7,9,3,1]         
 * Output: 12         
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob 
 * house 5 (money = 1).           
 * Total amount you can rob = 2 + 9 + 1 = 12.            
 * 
 * Constraints:            
 * 1 <= nums.length <= 100          
 * 0 <= nums[i] <= 400
 */ 

class Solution {
public:
    int rob_1(vector<int>& nums) {
        // Recursive (Top-down)
        return rob_1(nums, nums.size() - 1);
    }

    int rob_2(vector<int>& nums) {
        // Recursive + memory (Top-down)
        vector<int> memo(nums.size(), -1);
        return rob_2(nums, memo, nums.size() - 1);
    }

    int rob_3(vector<int>& nums) {
        // Iterative + memory (Bottom-up)
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> memo(nums.size(), -1);
        
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            memo[i] = max(memo[i-2] + nums[i], memo[i-1]);
        return memo[nums.size()-1];
    }
    
    int rob_4(vector<int>& nums) {
        // Iterative + two variables (Bottom-up)           
        if (nums.size() == 0) return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int tmp = prev1;
            prev1 = max(prev2 + nums[i], prev1);
            prev2 = tmp;
        }
        return prev1;
    }

private:
    int rob_1(vector<int>& nums, int i) {
        if (i < 0)  return 0;
        return max( rob( nums, i - 2) + nums[i], rob(nums, i - 1));
    }           

    int rob_2(vector<int>& nums, vector<int>& memo, int i) {
        if (i < 0)  return 0;
        if (memo[i] >= 0) return memo[i];
        int result = max( rob( nums, memo, i - 2) + nums[i], 
                          rob( nums, memo, i - 1));
        memo[i] = result;
        return result;
    }
};  

