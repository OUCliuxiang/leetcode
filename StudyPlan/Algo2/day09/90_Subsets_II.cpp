/**
 * Given an integer array nums that may contain duplicates, return all 
 * possible subsets (the power set).             
 * The solution set must not contain duplicate subsets. Return the solu-
 * tion in any order.           
 * 
 * Example 1:          
 * Input: nums = [1,2,2]            
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]            
 * 
 * Example 2:         
 * Input: nums = [0]            
 * Output: [[],[0]]           
 * 
 * Constraints:             
 * * 1 <= nums.length <= 10             
 * * -10 <= nums[i] <= 10      
 */

class Solution {
public:
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> cur;
        res.emplace_back(cur);
        for (int i = 0; i < n; i++){
            if (i>0 && find(nums.begin(), nums.begin()+i, nums[i]) != nums.begin()+i) continue;
            cur.emplace_back(nums[i]);
            res.emplace_back(cur);
            helper(nums, res, cur, i+1);
            cur.pop_back();
        }
        return res;
    }
private:
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur, int idx){
        if (idx == n) return;
        for (int i = idx; i < n; i ++){
            if (i>idx && find(nums.begin()+idx, nums.begin()+i, nums[i]) != nums.begin()+i) continue;
            cur.emplace_back(nums[i]);
            res.emplace_back(cur);
            helper(nums, res, cur, i+1);
            cur.pop_back();
        }
    }
};