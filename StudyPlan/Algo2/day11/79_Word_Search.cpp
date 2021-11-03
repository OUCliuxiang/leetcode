/**
 * Given an m x n grid of characters board and a string word, return true 
 * if word exists in the grid.         
 * The word can be constructed from letters of sequentially adjacent cells, 
 * where adjacent cells are horizontally or vertically neighboring. The 
 * same letter cell may not be used more than once.         
 * 
 * Example 1:       
 * Input: board = 
 * [["A","B","C","E"],
 *  ["S","F","C","S"],
 *  ["A","D","E","E"]], 
 * word = "ABCCED"          
 * Output: true           
 * 
 * Example 2:           
 * Input: board = 
 * [["A","B","C","E"],
 *  ["S","F","C","S"],
 *  ["A","D","E","E"]], 
 * word = "SEE"       
 * Output: true        
 * 
 * Example 3:          
 * Input: board = 
 * [["A","B","C","E"],
 *  ["S","F","C","S"],
 *  ["A","D","E","E"]], 
 * word = "ABCB"           
 * Output: false            
 * 
 * Constraints:        
 * * m == board.length           
 * * n = board[i].length           
 * * 1 <= m, n <= 6           
 * * 1 <= word.length <= 15           
 * * board and word consists of only lowercase and uppercase English letters.
 */ 

class Solution {
public:
    int DIRS[5] = {-1,0,1,0,-1};
    int len, Row, Col;
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        len = word.size();
        Row = board.size();
        Col = board[0].size();
        bool flag = false;
        for (int i = 0; i < Row; i ++)
            for (int j = 0; j < Col; j++)
                if(board[i][j] == word[0]){
                    dfs(board, word, flag, i, j, 0);
                    if (flag) return true;
                }
        return false;
    }
private:
    void dfs(std::vector<std::vector<char>>& board, 
             std::string& word, bool& flag, int r, int c, int idx){
        if(r<0 || c<0 || r>=Row || c>=Col || board[r][c] != word[idx]) return;
        
        if(idx == len-1 && word[idx] == board[r][c]){
            flag = true;
            return;
        }
        
        char tmp = board[r][c];
        board[r][c] = '*';
        if (tmp == word[idx])
            for(int i = 0; i < 4; i ++)
                dfs( board, word, flag, r+DIRS[i], c+DIRS[i+1], idx+1);
        board[r][c] = tmp;
    }
};
