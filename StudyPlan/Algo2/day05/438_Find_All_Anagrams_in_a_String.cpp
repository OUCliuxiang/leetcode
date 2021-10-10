/** 
 * Given two strings s and p, return an array of all the start indices 
 * of p's anagrams in s. You may return the answer in any order.         
 * An Anagram is a word or phrase formed by rearranging the letters of 
 * a different word or phrase, typically using all the original letters 
 * exactly once.                
 * 
 * Example 1:              
 * Input: s = "cbaebabacd", p = "abc"              
 * Output: [0,6]            
 * Explanation:            
 * The substring with start index = 0 is "cba", which is an anagram of 
 * "abc".           
 * The substring with start index = 6 is "bac", which is an anagram of 
 * "abc".            
 * 
 * Example 2:          
 * Input: s = "abab", p = "ab"            
 * Output: [0,1,2]            
 * Explanation:          
 * The substring with start index = 0 is "ab", which is an anagram of "ab".         
 * The substring with start index = 1 is "ba", which is an anagram of "ab".       
 * The substring with start index = 2 is "ab", which is an anagram of "ab".        
 * 
 * Constraints:          
 * * 1 <= s.length, p.length <= 3 * 104           
 * * s and p consist of lowercase English letters.
 */ 

class Solution {
public:
    vector<int> findAnagrams_failed(string s, string p) {
        if (p.size() > s.size()) return {};
        sort(p.begin(), p.end());
        vector<int> res;
        for (int i = 0; i <= s.size() - p.size(); i++){
            string sub = s.substr(i, p.size());
            sort(sub.begin(), sub.end());
            if (sub == p) res.emplace_back(i);
        }
        return res;
    }

    vector<int> findAnagrams_slideWindows(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> res;
        map<char, int> pm, sm;
        for (char c: p) pm[c] ++;
        for (int i = 0; i < s.size(); i++){
            sm[s[i]] ++;
            if(i >= p.size() && --sm[s[i-p.size()]]==0) 
                sm.erase(s[i-p.size()]);
            if(sm == pm) res.emplace_back(i-p.size()+1);
        }
        return res;
    }

    vector<int> findAnagrams_slidWinEffi(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> res;
        map<char, int> pm;
        for (char c: p) pm[c] ++;
        for (int i = 0; i < s.size(); i++){
            if (--pm[s[i]] == 0) pm.erase(s[i]);;
            if(i >= p.size() && ++pm[s[i-p.size()]]==0) 
                pm.erase(s[i-p.size()]);
            if(pm.empty()) res.emplace_back(i-p.size()+1);
        }
        return res;
    }
};        