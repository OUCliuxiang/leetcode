/**
 * Given n pairs of parentheses, write a function to generate all 
 * combinations of well-formed parentheses.         
 * 
 * Example 1:        
 * Input: n = 3        
 * Output: ["((()))","(()())","(())()","()(())","()()()"]        
 * 
 * Example 2:       
 * Input: n = 1        
 * Output: ["()"]       
 * 
 * Constraints:        
 * 1 <= n <= 8
 */ 

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        recursion(res, "", n, 0);
        return res;
    }
private:
    void recursion(std::vector<std::string>& res, 
                   std::string cur,
                   int lRe, int rRe){
        if (!lRe && !rRe){
            res.emplace_back(cur);
            return;
        }
        if(lRe) recursion(res, cur+'(', lRe-1, rRe+1);
        if(rRe) recursion(res, cur+')', lRe, rRe-1);
    }
};