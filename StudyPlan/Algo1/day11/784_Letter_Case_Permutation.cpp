/**
 * Given a string s, we can transform every letter individually to be 
 * lowercase or uppercase to create another string.           
 * Return a list of all possible strings we could create. You can 
 * return the output in any order.            
 * 
 * Example 1:          
 * Input: s = "a1b2"          
 * Output: ["a1b2","a1B2","A1b2","A1B2"]             
 * 
 * Example 2:             
 * Input: s = "3z4"         
 * Output: ["3z4","3Z4"]             
 * 
 * Example 3:           
 * Input: s = "12345"            
 * Output: ["12345"]            
 * 
 * Example 4:        
 * Input: s = "0"            
 * Output: ["0"]              
 * 
 * Constraints:           
 * * s will be a string with length between 1 and 12.          
 * * s will consist only of letters or digits.     
 */ 

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        helper(0, s, res);
        set<string> se(res.begin(), res.end());
        res.assign(se.begin(), se.end());
        return res;
    }
private:
    void helper(int idx, string& s, vector<string>& res){
        if(idx == s.size()){
            res.push_back(s);
            return;
        }
        for (int i = idx; i < s.size(); i ++){
            char tmp = s[i];
            if( tmp >= 'A' && tmp <= 'Z') {
                s[i] += 32;
                helper(i+1, s, res);
            }
            if( tmp >= 'a' && tmp <= 'z') {
                s[i] -= 32;
                helper(i+1, s, res);
            }
            s[i] = tmp;
            helper(i+1, s, res);
        }
    }
};