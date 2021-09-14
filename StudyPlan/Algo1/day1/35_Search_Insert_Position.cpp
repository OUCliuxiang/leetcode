/* 
 * Given a sorted array of distinct integers and a target value, 
 * return the index if the target is found. If not, return the index where 
 * it would be if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.      
 * 
 * Example 1:
 * Input: nums = [1,3,5,6], target = 5    
 * Output: 2
 * 
 * Example 2: 
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 * 
 * Example 3:
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 * 
 * Example 4:
 * Input: nums = [1,3,5,6], target = 0
 * Output: 0
 * 
 * Example 5:
 * Input: nums = [1], target = 0
 * Output: 0
 * 
 * Constraints:
 * 1 <= nums.length <= 104
 * -104 <= nums[i] <= 104
 * nums contains distinct values sorted in ascending order.
 * -104 <= target <= 104
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int under = 0, upper = nums.size()-1;
        if (target > nums.at(upper))
            return upper + 1;
        if (target <= nums.at(under))
            return under;
        while(under <= upper){
            int mid = under + (upper - under) / 2;
            if (target <= nums.at(mid)){
                if (target > nums.at(mid - 1))
                    return mid;
                else
                    upper = mid;
            }
            else
                under = mid + 1;
        }
        return 0;
    }

    int searchInsert_discuss(vector<int>& nums, int target) {
        vector<int>::iterator lower; 
        lower = lower_bound (nums.begin(), nums.end(), target); 
        return (lower-nums.begin());
    }
};
