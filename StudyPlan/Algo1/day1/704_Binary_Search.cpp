/* Given an array of integers nums which is sorted in ascending order,      
 * and an integer target, write a function to search target in nums.       
 * If target exists, then return its index. Otherwise, return -1.    
 
 * You must write an algorithm with O(log n) runtime complexity.
 
 * Example 1:    
 * Input: nums = [-1,0,3,5,9,12], target = 9    
 * Output: 4     
 * Explanation: 9 exists in nums and its index is 4

 * Example 2:      
 * Input: nums = [-1,0,3,5,9,12], target = 2     
 * Output: -1      
 * Explanation: 2 does not exist in nums so return -1
  
 * Constraints:     
 * 1 <= nums.length <= 104    
 * -104 < nums[i], target < 104
 * All the integers in nums are unique.   
 * nums is sorted in ascending order.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int rest = length;
        int upper = length, under = 0;
        int nowIndex = length / 2;
        int nowValue = nums[nowIndex];
        if ( nowValue == target) {
            return nowIndex;
        }
        rest /= 2;

        while (rest){
            if (target > nowValue){
                under = nowIndex;
                nowIndex = (nowIndex + upper)/2;
            }
            else{
                upper = nowIndex;
                nowIndex = (nowIndex + under) /2;
            }
            nowValue = nums[nowIndex];
            if (nowValue == target){
                return nowIndex;
            }
            rest/=2;
        }
        return -1;
    }
};