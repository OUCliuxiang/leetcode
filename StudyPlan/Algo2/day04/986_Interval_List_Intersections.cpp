/** 
 * You are given two lists of closed intervals, firstList and secondList, 
 * where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. 
 * Each list of intervals is pairwise disjoint and in sorted order.           
 * Return the intersection of these two interval lists.           
 * A closed interval [a, b] (with a <= b) denotes the set of real numbers 
 * x with a <= x <= b.            
 * The intersection of two closed intervals is a set of real numbers that 
 * are either empty or represented as a closed interval. For example, the 
 * intersection of [1, 3] and [2, 4] is [2, 3].           
 * 
 * Example 1:           
 * Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],
 * [8,12],[15,24],[25,26]]           
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]            
 * 
 * Example 2:          
 * Input: firstList = [[1,3],[5,9]], secondList = []             
 * Output: []          
 * 
 * Example 3:             
 * Input: firstList = [], secondList = [[4,8],[10,12]]           
 * Output: []          
 * 
 * Example 4:        
 * Input: firstList = [[1,7]], secondList = [[3,10]]        
 * Output: [[3,7]]          
 * 
 * Constraints:           
 * * 0 <= firstList.length, secondList.length <= 1000          
 * * firstList.length + secondList.length >= 1           
 * * 0 <= starti < endi <= 109           
 * * endi < starti+1           
 * * 0 <= startj < endj <= 109           
 * * endj < startj+1
 */ 

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.size() == 0 || secondList.size() == 0) return {};
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()){
            printf("i = %d, j = %d\t", i, j);
            if (firstList[i][1] < secondList[j][0]) {
                i ++;   printf("1");
            }
            else if (firstList[i][0] > secondList[j][1]) {
                j++;    printf("2");
            }
            
            else if (firstList[i][0] >=secondList[j][0] &&
                     firstList[i][1] <=secondList[j][1]){
                vector<int> tmp = {firstList[i][0], firstList[i][1]};
                res.emplace_back(tmp);
                i++; 
                printf("3");
            }
            else if (firstList[i][0] <=secondList[j][0] &&
                     firstList[i][1] >=secondList[j][1]){
                vector<int> tmp = {secondList[j][0], secondList[j][1]};
                res.emplace_back(tmp);
                j++; 
                printf("4");
            }
            else if (firstList[i][0] <=secondList[j][0] &&
                     firstList[i][1] >=secondList[j][0] &&
                     firstList[i][1] <=secondList[j][1]){
                vector<int> tmp = {secondList[j][0], firstList[i][1]};
                res.emplace_back(tmp);
                i ++;
                printf("5");
            }
            else if (firstList[i][0] >=secondList[j][0] &&
                     firstList[i][0] <=secondList[j][1] &&
                     firstList[i][1] >=secondList[j][1]){
                vector<int> tmp = {firstList[i][0], secondList[j][1]};
                res.emplace_back(tmp);
                j ++;
                printf("6");
            }
            printf("\n");
        }
        return res;
    }

    vector<vector<int>> intervalIntersection_concise( 
        vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if (firstList.size() == 0 || secondList.size() == 0) return {};
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()){
            int lower = max( firstList[i][0], secondList[j][0]);
            int upper = min( firstList[i][1], secondList[j][1]);
            if (lower <= upper)  res.push_back({lower, upper});
            if (firstList[i][1] > secondList[j][1]) j++;
            else i++;
        }
        return res;
    }
};