/* 
 * Write a function that reverses a string. The input string is given 
 * as an array of characters s.
 * 
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * Constraints:
 * 1 <= s.length <= 105
 * s[i] is a printable ascii character.
 * 
 * Follow up: Do not allocate extra space for another array. You must 
 * do this by modifying the input array in-place with O(1) extra memory.
 */ 

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (vector<char>::iterator left = s.begin(), right = s.end()-1; 
             right >= left; right --, left ++){
            iter_swap(left, right);
        }
    }

    void reverseString_second(vector<char>& s) {
        reverse(s.begin(), s.end());
    }    

    void reverseString_third(vector<char>& s) {
        vector<char> st( s.rbegin(), s.rend());
        s = st;
    }
}; 

