/** 
 * Given an m x n binary matrix mat, return the distance of the nearest 
 * 0 for each cell.
 * 
 * The distance between two adjacent cells is 1.
 * 
 * Example 1:
 * Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: [[0,0,0],[0,1,0],[0,0,0]]
 * 
 * Example 2:
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 * 
 * Constraints:
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 104
 * 1 <= m * n <= 104
 * mat[i][j] is either 0 or 1.
 * There is at least one 0 in mat.
 */ 

class Solution {
public:
    vector<vector<int>> updateMatrix_TLE(vector<vector<int>>& mat) {
        int Row = mat.size(), Col = mat[0].size();
        for (int i = 0; i < Row; i ++){
            for (int j = 0; j < Col; j++){
                if (mat[i][j] != 0){
                    int minDis = 0x7fff;
                    list<pair<int, int>> itemList;
                    itemList.push_back(make_pair(i,j));
                    while(!itemList.empty()){
                        pair<int, int> thisItem = itemList.front();
                        itemList.pop_front();
                        int row = get<0>(thisItem), col = get<1>(thisItem);
                        if(row < 0 || row == Row || col < 0 || col == Col)
                            continue;
                        if(mat[row][col] == 0 ){
                            minDis = abs(row-i)+abs(col-j);
                            break;
                        }
                        itemList.push_back(make_pair(row-1, col));
                        itemList.push_back(make_pair(row+1, col));
                        itemList.push_back(make_pair(row, col-1));
                        itemList.push_back(make_pair(row, col+1));
                    }
                    mat[i][j] = minDis;
                    itemList.~list();
                } 
            }
        }
        return mat;
    }

    int DIRS[5] = {-1,0,1,0,-1}, Row, Col;
    vector<vector<int>> updateMatrix_discuss(vector<vector<int>>& mat) {
        Row = mat.size();
        Col = mat[0].size();
        int maxDis = Row+Col;
        queue<pair<int, int>> q; 
        for (int i = 0; i < Row; i++ ){
            for (int j = 0; j < Col; j++){
                mat[i][j] == 0 ? q.push(make_pair(i, j)) : void( mat[i][j] = maxDis); 
            }
        }
        while(!q.empty()){
            auto [x, y] = q.front();    q.pop();
            for (int i = 0; i < 4; i++){
                int x1 = x + DIRS[i], y1 = y + DIRS[i+1];
                if(isValid(x1, y1) && mat[x1][y1] == maxDis){
                    q.push(make_pair(x1, y1));
                    mat[x1][y1] = min(mat[x1][y1], mat[x][y] + 1);
                }                  
            }
        }
        
        return mat;
    }
    
private:
    bool isValid(int x, int y){
        if (x >= 0 && x < Row && y >=0 && y < Col ) return true;
        return false;
    }
}; 