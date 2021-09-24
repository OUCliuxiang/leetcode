/** 
 * An image is represented by an m x n integer grid image where image[i][j] 
 * represents the pixel value of the image.
 * You are also given three integers sr, sc, and newColor. You should 
 * perform a flood fill on the image starting from the pixel image[sr][sc].
 * 
 * To perform a flood fill, consider the starting pixel, plus any pixels 
 * connected 4-directionally to the starting pixel of the same color as 
 * the starting pixel, plus any pixels connected 4-directionally to those 
 * pixels (also with the same color), and so on. Replace the color of all 
 * of the aforementioned pixels with newColor.
 * Return the modified image after performing the flood fill.
 * 
 * Example 1:
 * Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally 
 * connected to the starting pixel.
 * 
 * Example 2:
 * Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
 * Output: [[2,2,2],[2,2,2]]
 * 
 * Constraints:
 * m == image.length
 * n == image[i].length
 * 1 <= m, n <= 50
 * 0 <= image[i][j], newColor < 216
 * 0 <= sr < m
 * 0 <= sc < n
 */ 

class Solution {
public:
    vector<vector<int>> floodFill_dfs(vector<vector<int>>& image, 
                                  int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        
        int oldColor = image[sr][sc];
        if (image[sr][sc] != newColor){
            dfs(image, sr, sc, oldColor, newColor);
        }
        return image;
    }

    vector<vector<int>> floodFill_bfs(vector<vector<int>>& image, 
                                int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        
        int oldColor = image[sr][sc];
        int Row = image.size(), Col = image[0].size();
        list<pair<int, int>> itemList;
        itemList.push_back( ( make_pair(sr, sc)));
        while( !itemList.empty()){
            pair<int, int> thisItem = itemList.front();
            itemList.pop_front();
            int thisRow = get<0>(thisItem), thisCol = get<1>(thisItem);
            if (thisRow < 0 || thisRow == Row || thisCol < 0 || 
                thisCol == Col || image[thisRow][thisCol] != oldColor)
                continue;
            image[thisRow][thisCol] = newColor;
            
            itemList.push_back( ( make_pair(thisRow-1, thisCol)));
            itemList.push_back( ( make_pair(thisRow+1, thisCol)));
            itemList.push_back( ( make_pair(thisRow, thisCol-1)));
            itemList.push_back( ( make_pair(thisRow, thisCol+1)));
        }
        return image;
    
    
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor){
        if (sr < 0 || sr == image.size() || sc < 0 || sc == image[0].size() || image[sr][sc] != oldColor) return;
        image[sr][sc] = newColor;
        dfs(image, sr-1, sc, oldColor, newColor);
        dfs(image, sr+1, sc, oldColor, newColor);
        dfs(image, sr, sc-1, oldColor, newColor);
        dfs(image, sr, sc+1, oldColor, newColor);
    }
};


