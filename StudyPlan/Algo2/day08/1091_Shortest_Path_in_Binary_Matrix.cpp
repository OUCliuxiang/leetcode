/** 
 * Given an n x n binary matrix grid, return the length of the shortest 
 * clear path in the matrix. If there is no clear path, return -1.         
 * A clear path in a binary matrix is a path from the top-left cell (i.e., 
 * (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:         
 * * All the visited cells of the path are 0.          
 * * All the adjacent cells of the path are 8-directionally connected 
 *   (i.e., they are different and they share an edge or a corner).      
 * 
 * The length of a clear path is the number of visited cells of this path.          
 * Example 1:         
 * Input: grid = [[0,1],[1,0]]          
 * Output: 2           
 * 
 * Example 2:         
 * Input: grid = [[0,0,0],[1,1,0],[1,1,0]]         
 * Output: 4            
 * 
 * Example 3:        
 * Input: grid = [[1,0,0],[1,1,0],[1,1,0]]         
 * Output: -1             
 */        
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0 ) return -1;
        if (n == 1) return 1;
        
        queue<pair<int,int>> q;
        grid[0][0] ++;
        q.push(make_pair(0,0));
        while(!q.empty()){
            pair<int, int> pos = q.front();
            q.pop();
            int row = get<0>(pos);
            int col = get<1>(pos);
            for (int i = row-1; i < row+2; i++){
                for (int j = col-1; j < col+2; j++){
                    if (i>=0 && j>=0 && i<n && j<n && grid[i][j] == 0){
                        if (i == n-1 && j == n-1) return grid[row][col] + 1;
                        grid[i][j] = grid[row][col] + 1; 
                        q.push({i,j});
                }
            }
        }
        return -1;
    }
};