/** 
 * Given an array of positive integers nums and a positive integer tar-
 * get, return the minimal length of a contiguous subarray [numsl, num-
 * sl+1, ..., numsr-1, numsr] of which the sum is greater than or equal 
 * to target. If there is no such subarray, return 0 instead.       
 * 
 * Example 1:           
 * Input: target = 7, nums = [2,3,1,2,4,3]            
 * Output: 2           
 * Explanation: The subarray [4,3] has the minimal length under the pro-
 * blem constraint.           
 * 
 * Example 2:         
 * Input: target = 4, nums = [1,4,4]         
 * Output: 1             
 * 
 * Example 3:             
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]              
 * Output: 0           
 * 
 * Constraints:            
 * * 1 <= target <= 109           
 * * 1 <= nums.length <= 105              
 * * 1 <= nums[i] <= 105
 */ 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = 0x7fff, s = 0;
        for(int i = 0, j = 0; j < nums.size(); j++){
            s += nums[j];
            while( i<=j && s >=target){
                size = min( size, j-i+1);
                s -= nums[i++];
            }
        }
        return size == 0x7fff ? 0 : size;
    }
};