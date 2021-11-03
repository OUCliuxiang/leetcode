/**
 * Given a collection of numbers, nums, that might contain duplicates, 
 * return all possible unique permutations in any order.           
 * 
 * Example 1:          
 * Input: nums = [1,1,2]          
 * Output:            
 * [[1,1,2],            
 *  [1,2,1],          
 *  [2,1,1]]           
 * 
 * Example 2:          
 * Input: nums = [1,2,3]              
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]           
 * 
 * Constraints:          
 * * 1 <= nums.length <= 8           
 * * -10 <= nums[i] <= 10           
 */ 

class Solution {
public:
    vector<vector<int>> permuteUnique_nxtper(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do{
            res.emplace_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return res;
    }

    int len;
    vector<vector<int>> permute_wout_dupli(vector<int>& nums) {
        len = nums.size();
        sort( nums.begin(), nums.end());
        vector<vector<int>> res;
        recursion(res, nums, 0);
        return res;
    }
    vector<vector<int>> permuteUnique_w_dupli(vector<int>& nums) {
        len = nums.size();
        sort( nums.begin(), nums.end());
        vector<vector<int>> res;
        recursion_dupli(res, nums, 0);
        return res;
    }

private:
    void recursion_dupli( vector<vector<int>>& res, 
                    vector<int> nums, int idx){
        if (idx == len){
            res.emplace_back(nums);
            return;
        }
        for (int i = idx; i < len; i ++){
            if (i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            recursion(res, nums, idx+1);
        }
    }
    void recursion( vector<vector<int>>& res, 
                    vector<int>& nums, int idx){
        if (idx == len){
            res.emplace_back(nums);
            return;
        }
        for (int i = idx; i < len; i ++){
            swap(nums[i], nums[idx]);
            recursion(res, nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};