/**
 * There is an integer array nums sorted in ascending order (with distinct 
 * values).              
 * Prior to being passed to your function, nums is possibly rotated at an 
 * unknown pivot index k (1 <= k < nums.length) such that the resulting 
 * array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., 
 * nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated 
 * at pivot index 3 and become [4,5,6,7,0,1,2].            
 * Given the array nums after the possible rotation and an integer target,
 * return the index of target if it is in nums, or -1 if it is not in nums.        
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Example 1:          
 * Input: nums = [4,5,6,7,0,1,2], target = 0           
 * Output: 4           
 * 
 * Example 2:          
 * Input: nums = [4,5,6,7,0,1,2], target = 3             
 * Output: -1            
 * 
 * Example 3:            
 * Input: nums = [1], target = 0           
 * Output: -1            
 * 
 * Constraints:                
 * * 1 <= nums.length <= 5000            
 * * -104 <= nums[i] <= 104       
 * * All values of nums are unique.           
 * * nums is an ascending array that is possibly rotated.        
 * * -104 <= target <= 104         
 */ 

class Solution {
public:
    int search_mine1(vector<int>& nums, int target) {
        vector<int>::iterator it = find(nums.begin(), nums.end(), target);
        return it == nums.end() ? -1 : it - nums.begin();
    }

    int search_mine2(vector<int>& nums, int target) {
        vector<int>::iterator it = min_element(nums.begin(), nums.end());
        int shift = it - nums.begin();
        for (int i = 0; i < shift; i++){
            nums.emplace_back(nums[0]);
            nums.erase(nums.begin());
        }
        nums.erase(max_element(nums.begin(), nums.end())+1, nums.end());
        if (!binary_search(nums.begin(), nums.end(), target))
            return -1;
        
        return (lower_bound(nums.begin(), nums.end(), target) - nums.begin() + shift)%nums.size();
    }

    int search_discuss(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, middle;
        while(left <= right){
            middle = (left + right)/2;
            if (nums[middle] == target)
                return middle;
            if (nums[left] <= nums[middle]){
                if (target >= nums[left] && target < nums[middle])
                    right = middle-1;
                else
                    left = middle + 1;
            }
            else{
                if (target > nums[middle] && target <= nums[right])
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }
        return -1;
    }
};     
