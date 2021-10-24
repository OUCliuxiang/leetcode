/** 
 * Given an integer array nums of unique elements, return all possible 
 * subsets (the power set).         
 * The solution set must not contain duplicate subsets. Return the solu-
 * tion in any order.         
 * 
 * Example 1:           
 * Input: nums = [1,2,3]            
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]          
 * 
 * Example 2:       
 * Input: nums = [0]          
 * Output: [[],[0]]            
 * 
 * Constraints:          
 * * 1 <= nums.length <= 10            
 * * -10 <= nums[i] <= 10            
 * * All the numbers of nums are unique.      
 */        

class Solution {
public:
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        n = nums.size();
        vector<int> cur;
        res.emplace_back(cur);
        for (int i = 0; i < n; i++){
            cur.emplace_back(nums[i]);
            res.emplace_back(cur);
            helper(nums, res, cur, i+1);
            cur.pop_back();
        }
        return res;
    }
private:
    void helper(vector<int>& nums, vector<vector<int>>& res, 
                vector<int>& cur, int idx){
        if (idx == n) return;
        for (int i = idx; i < n; i ++){
            cur.emplace_back(nums[i]);
            res.emplace_back(cur);
            helper(nums, res, cur, i+1);
            cur.pop_back();
        }
    }
}; 

