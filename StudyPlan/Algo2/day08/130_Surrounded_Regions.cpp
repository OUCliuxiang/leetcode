/**
 * Given an m x n matrix board containing 'X' and 'O', capture all regions 
 * that are 4-directionally surrounded by 'X'.        
 * A region is captured by flipping all 'O's into 'X's in that surrounded 
 * region.       
 * 
 * Example 1:        
 * Input: board = [         
 * ["X","X","X","X"],         
 * ["X","O","O","X"],         
 * ["X","X","O","X"],          
 * ["X","O","X","X"]]            
 * Output:[          
 * ["X","X","X","X"],          
 * ["X","X","X","X"],           
 * ["X","X","X","X"],         
 * ["X","O","X","X"]]             
 * Explanation: Surrounded regions should not be on the border, which means 
 * that any 'O' on the border of the board are not flipped to 'X'. Any 'O' 
 * that is not on the border and it is not connected to an 'O' on the border 
 * will be flipped to 'X'. Two cells are connected if they are adjacent cells 
 * connected horizontally or vertically.         
 * 
 * Example 2:       
 * Input: board = [["X"]]         
 * Output: [["X"]]            
 * 
 * Constraints:          
 * * m == board.length          
 * * n == board[i].length           
 * * 1 <= m, n <= 200            
 * * board[i][j] is 'X' or 'O'.         
 */         

class Solution {
public:
    int DIRS[5] = {-1,0,1,0,-1};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if(n<3 || m < 3) return;
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i ++){
            if(board[i][0] == 'O') {
                board[i][0] = 'V';
                q.push({i,0});
            }
            if(board[i][m-1] == 'O'){ 
                board[i][m-1] = 'V';
                q.push({i,m-1});
            }
        }
        for(int i = 0; i < m; i ++){
            if(board[0][i] == 'O'){
                board[0][i] = 'V';
                q.push({0,i});
            }
            if(board[n-1][i] == 'O'){ 
                board[n-1][i] = 'V';
                q.push({n-1, i});
            }
        }
        while(!q.empty()){
            pair<int, int> pos = q.front(); q.pop();
            int row = get<0>(pos);
            int col = get<1>(pos);
            for(int i = 0; i < 4; i ++){
                int newRow = row + DIRS[i];
                int newCol = col + DIRS[i+1];
                if (newRow >=0 && newCol >=0 && 
                    newRow < n && newCol < m &&
                    board[newRow][newCol] == 'O'){
                    board[newRow][newCol] = 'V';
                    q.push({newRow, newCol});
                }
            }
        }
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                board[i][j] = board[i][j] == 'V' ? 'O' : 'X';
    }
}; 

