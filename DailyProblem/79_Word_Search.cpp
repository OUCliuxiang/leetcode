/** 
 * Given an m x n grid of characters board and a string word, return true if 
 * word exists in the grid.           
 * The word can be constructed from letters of sequentially adjacent cells, 
 * where adjacent cells are horizontally or vertically neighboring. The same 
 * letter cell may not be used more than once.      
 * 
 * Example 1:         
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 
 * word = "ABCCED"         
 * Output: true
 * 
 * Example 2:           
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 
 * word = "SEE"        
 * Output: true           
 * 
 * Example 3:        
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 
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
// WA_due_to_without_visited_recovery      

public:
    int DIRS[5] = {-1, 0, 1, 0, -1};
    int Row, Col;
    bool exist(vector<vector<char>>& board, string word) {
        Row = board.size();
        Col = board[0].size();
        bool flag = false;
        for (int i = 0; i < Row; i ++)
            for (int j = 0; j < Col; j ++)
                if (board[i][j] == word[0]){
                    vector<vector<bool>> mask(Row, vector<bool>(Col, false));
                    dfs(board, word, flag, mask, i, j, 0);
                    if (flag == true)
                        return true;
                }
        return false;
    }
private:
    void dfs(vector<vector<char>>& board, string& word, bool& flag, 
             vector<vector<bool>>& mask, int i, int j, int k){
        if (i < 0 || i >= Row || j < 0 || j >= Col) return;
        printf("%d(%c): [%d, %d]\n", k, word[k], i, j);
        if (mask[i][j]) return;
        if (board[i][j] != word[k]) return;
        mask[i][j] = true;
        if (k == word.size()-1) {
            flag = true;
            return;
        }
        for (int l = 0; l < 4; l++)
            dfs(board, word, flag, mask, i+DIRS[l], j+DIRS[l+1], k+1);
    }
};

class Solution {
// AV Version after ``visited'' problem's resolved         

public:
    int DIRS[5] = {-1, 0, 1, 0, -1};
    int Row, Col;
    bool exist(vector<vector<char>>& board, string word) {
        Row = board.size();
        Col = board[0].size();
        bool flag = false;
        for (int i = 0; i < Row; i ++)
            for (int j = 0; j < Col; j ++)
                if (board[i][j] == word[0]){
                    vector<vector<bool>> mask(Row, vector<bool>(Col, false));
                    dfs(board, word, flag, mask, i, j, 0);
                    if (flag == true)
                        return true;
                }
        return false;
    }
private:
    void dfs(vector<vector<char>>& board, string& word, bool& flag, 
             vector<vector<bool>>& mask, int i, int j, int k){
        if (i < 0 || i >= Row || j < 0 || j >= Col) return;
        if (mask[i][j]) return;
        if (board[i][j] != word[k]) return;
        mask[i][j] = true;
        if (k == word.size()-1) {
            flag = true;
            return;
        }
        for (int l = 0; l < 4; l++)
            dfs(board, word, flag, mask, i+DIRS[l], j+DIRS[l+1], k+1);
        mask[i][j] = false;
    }
};

class Solution {
// Improvement from the previou that replacing visited matrix with 
// other char. 

public:
    int DIRS[5] = {-1, 0, 1, 0, -1};
    int Row, Col;
    bool exist(vector<vector<char>>& board, string word) {
        Row = board.size();
        Col = board[0].size();
        bool flag = false;
        for (int i = 0; i < Row; i ++)
            for (int j = 0; j < Col; j ++)
                if (board[i][j] == word[0]){
                    dfs(board, word, flag, i, j, 0);
                    if (flag == true)
                        return true;
                }
        return false;
    }
private:
    void dfs(vector<vector<char>>& board, string& word, 
             bool& flag, int i, int j, int k){
        if (i < 0 || i >= Row || j < 0 || j >= Col) return;
        if (board[i][j] != word[k]) return;
        if (k == word.size()-1) {
            flag = true;
            return;
        }
        char t = board[i][j];
        board[i][j] = '*';
        for (int l = 0; l < 4; l++)
            dfs(board, word, flag, i+DIRS[l], j+DIRS[l+1], k+1);
        board[i][j] = t;
    }
};