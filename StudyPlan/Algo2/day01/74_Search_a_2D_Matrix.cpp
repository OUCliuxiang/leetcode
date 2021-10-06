/**    
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * * Integers in each row are sorted from left to right.
 * * The first integer of each row is greater than the last integer of the 
 * previous row.        
 * 
 * Example 1:
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * Example 2:
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * Constraints:
 * * m == matrix.length
 * * n == matrix[i].length
 * * 1 <= m, n <= 100
 * * -104 <= matrix[i][j], target <= 104
 */         
class Solution {
public:
    bool searchMatrix_mine(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size()-1;
        for(int i = 0; i < matrix.size(); i ++)
            if (target >= matrix[i].at(0) && target <= matrix[i].at(n))
                return binary_search(matrix[i].begin(), matrix[i].end(), target);
        return false;
    }

    bool searchMatrix_mine2(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size()-1;
        for(int i = 0; i < matrix.size(); i ++)
            if (target >= matrix[i].at(0) && target <= matrix[i].at(n)){
                int left = 0, right = n, middle;
                while(left <= right){
                    middle = (left + right) / 2;
                    if (matrix[i][middle] == target)    return true;
                    if (matrix[i][middle] > target)
                        right = middle - 1;
                    else
                        left = middle + 1;
                }
                return false;
            }
        return false;
    }
};