/** 
 * Given an integer array nums, return all the triplets [nums[i], nums[j], 
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + 
 * nums[k] == 0.       
 * Notice that the solution set must not contain duplicate triplets.       
 * 
 * Example 1:       
 * Input: nums = [-1,0,1,2,-1,-4]         
 * Output: [[-1,-1,2],[-1,0,1]]            
 * 
 * Example 2:        
 * Input: nums = []         
 * Output: []        
 * 
 * Example 3:         
 * Input: nums = [0]      
 * Output: []           
 * 
 * Constraints:        
 * * 0 <= nums.length <= 3000     
 * * -105 <= nums[i] <= 105
 */ 
class Solution {
public:
    vector<vector<int>> threeSum_unique(vector<int>& nums) {
        if(nums.size()<3) return {};
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++){
            // printf("%d",i);
            int target = -nums[i];
            int front = i + 1, back = nums.size() - 1;
            while(front < back){
                if (nums[front] + nums[back] > target)
                    back --;
                else if (nums[front] + nums[back] < target)
                    front ++;
                else{
                    printf("%d,%d,%d\n",i, front, back);
                    vector<int> tmp = {nums[i], nums[front], nums[back]};
                    res.emplace_back(tmp);
                    front ++;back --;
                }
            }
            while(i < nums.size()-2 && nums[i] == nums[i+1]) i++;
        }
        std::sort(res.begin(), res.end());
        res.erase(std::unique(res.begin(), res.end()), res.end());
        return res;
    }
    vector<vector<int>> threeSum_without_unique(vector<int>& nums) {
        if(nums.size()<3) return {};
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++){
            int target = -nums[i];
            int front = i + 1, back = nums.size() - 1;
            while(front < back){
                if (nums[front] + nums[back] > target)
                    back --;
                else if (nums[front] + nums[back] < target)
                    front ++;
                else{
                    vector<int> tmp = {nums[i], nums[front], nums[back]};
                    res.emplace_back(tmp);
                    front ++; back --;
                    while(front < back && nums[front] == nums[front-1]) front ++;
                    while(front < back && nums[back] == nums[back+1]) back --;
                }
            }
            while(i < nums.size()-2 && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};       

