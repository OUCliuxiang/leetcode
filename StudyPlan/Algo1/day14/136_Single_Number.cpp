/** 
 * Given a non-empty array of integers nums, every element appears 
 * twice except for one. Find that single one.
 * You must implement a solution with a linear runtime complexity and
 *  use only constant extra space.
 * 
 * Example 1:
 * Input: nums = [2,2,1]
 * Output: 1
 * 
 * Example 2:
 * Input: nums = [4,1,2,1,2]
 * Output: 4
 * 
 * Example 3:
 * Input: nums = [1]
 * Output: 1
 * 
 * Constraints:
 * 1 <= nums.length <= 3 * 104
 * -3 * 104 <= nums[i] <= 3 * 104
 * Each element in the array appears twice except for one element 
 * which appears only once.
 */ 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)    return nums.at(0);
        map<int, int> m;
        for (vector<int>::iterator it = nums.begin(); 
             it != nums.end(); it ++){
            if (m.find(*it) == m.end())
                m.insert({*it, 1});
            else
                m[*it] ++;
        }
        for (map<int, int>::iterator it = m.begin();
             it != m.end(); it ++)
            if(it -> second == 1)
                return it -> first;
        return nums.back();
    }

    int singleNumber_bitManipulation(vector<int>& nums) {
        if(nums.size() == 1)    return nums.at(0);
        int result = 0;
        for (int i = 0; i < nums.size(); i++){
            result ^= nums[i];
        }
        return result;
    }
};