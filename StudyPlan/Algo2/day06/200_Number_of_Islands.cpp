/** 
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) 
 * and '0's (water), return the number of islands.            
 * An island is surrounded by water and is formed by connecting adjacent 
 * lands horizontally or vertically. You may assume all four edges of the 
 * grid are all surrounded by water.                
 * 
 * Example 1:              
 * Input: grid = [           
 * ["1","1","1","1","0"],         
 * ["1","1","0","1","0"],           
 * ["1","1","0","0","0"],       
 * ["0","0","0","0","0"]        
 * ]         
 * Output: 1            
 * 
 * Example 2:          
 * Input: grid = [          
 * ["1","1","0","0","0"],         
 * ["1","1","0","0","0"],       
 * ["0","0","1","0","0"],        
 * ["0","0","0","1","1"]           
 * ]        
 * Output: 3            
 * 
 * Constraints:           
 * * m == grid.length           
 * * n == grid[i].length           
 * * 1 <= m, n <= 300          
 * * grid[i][j] is '0' or '1'.
 */

class Solution {
public:
    int Row, Col, DIRS[5] = {-1,0,1,0,-1};
    int numIslands( vector<vector<char>>& grid) {
        Row = grid.size();
        Col = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < Row; i++)
            for (int j = 0; j < Col; j++)
                if (grid[i][j] == '1'){
                    dfs(grid, i, j);
                    cnt++;
                }
        return cnt; 
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= Row || j >= Col || grid[i][j] != '1') return;
        grid[i][j] = '0';
        for(int l = 0; l < 4; l++)
            dfs(grid, i+DIRS[l], j + DIRS[l+1]);
    }
};