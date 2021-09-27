/**
 * Given two integers n and k, return all possible combinations of k 
 * numbers out of the range [1, n].
 * You may return the answer in any order.
 * 
 * Example 1:
 * Input: n = 4, k = 2
 * Output:  
 * [[2,4],
 * [3,4],
 * [2,3],
 * [1,2],
 * [1,3],
 * [1,4],]
 * 
 * Example 2:
 * Input: n = 1, k = 1
 * Output: [[1]]
 * 
 * Constraints:
 * 1 <= n <= 20
 * 1 <= k <= n
 */ 

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> item;
        helper(1, k, n, res, item);
        return res;
    }
private:
    void helper(int idx, int k, int n, vector<vector<int>>& res, vector<int>& item){
        if (item.size() == k){
            res.push_back(item);
            return;
        }
        for (int i = idx; i <= n; i++){
            item.push_back(i);
            helper(i+1, k, n, res, item);
            item.pop_back();
        }
    }
};