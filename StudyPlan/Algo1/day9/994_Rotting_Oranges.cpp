/** 
 * You are given an m x n grid where each cell can have one of three values:
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * 
 * Every minute, any fresh orange that is 4-directionally adjacent to a 
 * rotten orange becomes rotten.
 * Return the minimum number of minutes that must elapse until no cell 
 * has a fresh orange. If this is impossible, return -1.
 * 
 * Example 1:
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * Example 2:
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) 
 * is never rotten, because rotting only happens 4-directionally.
 * 
 * Example 3:
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, 
 * the answer is just 0.
 * 
 * Constraints:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 */ 

class Solution {
public:
    int Row, Col;
    int DIRS[5] = {-1, 0, 1, 0, -1};
    int orangesRotting(vector<vector<int>>& grid) {
        Row = grid.size();
        Col = grid[0].size();
        queue<tuple<int, int, int>> q;
        int step = 0;
        for (int i = 0; i < Row; i ++)
            for (int j = 0; j < Col; j ++)
                if (grid[i][j] == 2)
                    q.push(make_tuple(i, j, step));
        
        while(!q.empty()){
            auto [x, y, s] = q.front(); q.pop();
            for (int i = 0; i < 4; i++){
                int x1 = x + DIRS[i], y1 = y + DIRS[i+1];
                if (isValid(x1, y1, grid)){
                    grid[x1][y1] = 2;
                    q.push(make_tuple(x1, y1, s+1));
                }
            }
            step = s;
        }
        
        for (int i = 0; i < Row; i ++)
            for (int j = 0; j < Col; j ++)
                if (grid[i][j] == 1)
                    return -1;
        
        return step;
    }
private:
    bool isValid(int x, int y, vector<vector<int>>& grid){
        if (x >= 0 && x < Row && y >= 0 && y < Col && grid[x][y] == 1)
            return true;
        return false;
    }
};