/** 
 * Suppose an array of length n sorted in ascending order is rotated between 
 * 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
 * * [4,5,6,7,0,1,2] if it was rotated 4 times.      
 * * [0,1,2,4,5,6,7] if it was rotated 7 times.
 * 
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time 
 * results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 * 
 * Given the sorted rotated array nums of unique elements, return the minimum 
 * element of this array.
 * You must write an algorithm that runs in O(log n) time.
 * 
 * Example 1:
 * Input: nums = [3,4,5,1,2]
 * Output: 1
 * Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 * 
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2]
 * Output: 0
 * Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 
 * times.
 * 
 * Example 3:
 * Input: nums = [11,13,15,17]
 * Output: 11
 * Explanation: The original array was [11,13,15,17] and it was rotated 4 
 * times. 
 */ 

class Solution {
public:
    int findMin_min_ele(vector<int>& nums) {
        if (nums.size() == 0) return nums[0];
        return *(min_element(nums.begin(), nums.end()));
    }
    int findMin_sort(vector<int>& nums) {
        if (nums.size() == 0) return nums[0];
        sort(nums.begin(), nums.end());
        return nums[0];
    }
    class Solution {
public:
    int findMin_binary(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size()-1, middle;
        if (nums[left] < nums[right])   return nums[left];
        while(left < right){
            middle = (left + right) / 2;
            if (nums[left]<nums[middle])
                left = middle;
            else
                right = middle;
        }
        return nums[left+1];
    }
};
};
