/**
 * There are n cities. Some of them are connected, while some are not. If 
 * city a is connected directly with city b, and city b is connected dire-
 * ctly with city c, then city a is connected indirectly with city c.          
 * A province is a group of directly or indirectly connected cities and no 
 * other cities outside of the group.          
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if 
 * the ith city and the jth city are directly connected, and isConnected[i]
 * [j] = 0 otherwise.          
 * Return the total number of provinces.          
 * 
 * Example 1:           
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]           
 * Output: 2           
 * 
 * Example 2:        
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]           
 * Output: 3           
 */

class Solution {
public:
    int n;
    int findCircleNum( vector<vector<int>>& isConnected) {
        n = isConnected.size();
        int cnt = 0;
        for (int i = 0; i < n; i ++)
            if (isConnected[i][i] == 1){
                dfs(isConnected, i, i);
                cnt ++;
            }
        return cnt;
    }
private:
    void dfs(vector<vector<int>>& isConnected, int i, int j){
        if (i < 0 || j < 0 || i >= n || j >= n || 
            isConnected[i][j] != 1 || isConnected[j][i] != 1) return;
        isConnected[i][j] = 0;
        if(i != j) isConnected[j][i] = 0;
        for (int l = 0; l < n; l++)
            dfs(isConnected, l, i);
    }
};        