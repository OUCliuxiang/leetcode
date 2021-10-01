/**
 * Given a triangle array, return the minimum path sum from top to bottom.
 * For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 * 
 * Example 1:
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 *    2
 *   3 4
 *  6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 
 * (underlined above).
 * 
 * Example 2:
 * Input: triangle = [[-10]]
 * Output: -10
 * 
 * Constraints:
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -104 <= triangle[i][j] <= 104
 */ 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        if (triangle.size() == 1) return triangle.at(0).at(0);
        vector<int> minPath( triangle.back());
        for (int layer = triangle.size() - 2; layer >= 0 ; layer --)
            for (int node = 0; node <= layer; node ++)
                minPath[node] = 
                    min( minPath[node], minPath[node + 1]) 
                    + triangle[layer][node];
        return minPath[0];
    }
};