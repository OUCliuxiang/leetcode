/**
 * Given a collection of candidate numbers (candidates) and a target 
 * number (target), find all unique combinations in candidates where 
 * the candidate numbers sum to target.          
 * Each number in candidates may only be used once in the combination.         
 * Note: The solution set must not contain duplicate combinations.         
 * 
 * Example 1:        
 * Input: candidates = [10,1,2,7,6,1,5], target = 8            
 * Output:       
 * [[1,1,6], [1,2,5], [1,7], [2,6]]       
 * 
 * Example 2:         
 * Input: candidates = [2,5,2,1,2], target = 5            
 * Output:           
 * [[1,2,2], [5]] 
 */      

class Solution {
public:
    int len;
    std::vector<std::vector<int>> combinationSum2(
    std::vector<int>& nums, int target) {
        len = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        finder(res, cur, nums, target, 0);
        return res;
    }
private:
    void finder(std::vector<std::vector<int>>& res,
                std::vector<int>& cur,
                std::vector<int>& nums,
                int target, 
                int idx){
        if(!target){
            res.emplace_back(cur);
            return;
        }
        for(int i = idx; i < len && target >= nums[i]; i++){
            if (i != idx && nums[i] == nums[idx]) continue;
            cur.emplace_back(nums[i]);
            finder(res, cur, nums, target-nums[i], i+1);
            cur.pop_back();
        }
    }
};