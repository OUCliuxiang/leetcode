/** 
 * Given two strings s and t, return true if they are equal when both are typed 
 * into empty text editors. '#' means a backspace character.       
 * Note that after backspacing an empty text, the text will continue empty.       
 * 
 * Example 1:          
 * Input: s = "ab#c", t = "ad#c"            
 * Output: true            
 * Explanation: Both s and t become "ac".         
 * 
 * Example 2:          
 * Input: s = "ab##", t = "c#d#"          
 * Output: true         
 * Explanation: Both s and t become "".         
 * 
 * Example 3:          
 * Input: s = "a##c", t = "#a#c"          
 * Output: true             
 * Explanation: Both s and t become "c".          
 * 
 * Example 4:              
 * Input: s = "a#c", t = "b"           
 * Output: false            
 * Explanation: s becomes "c" while t becomes "b".          
 * 
 * Constraints:           
 * * 1 <= s.length, t.length <= 200              =
 * * s and t only contain lowercase letters and '#' characters.      
 */     
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        for(int i = 0; i < s.length(); i++){
            if (i > 0 && s[i] == '#'){ 
                s.erase(i-1, 2);
                i-=2;
            }
            while(s[0] == '#') s.erase(0,1);
        }
        for(int i = 0; i < t.length(); i++){
            if (i > 0 && t[i] == '#'){ 
                t.erase(i-1, 2);
                i-=2;
            }
            while(t[0] == '#') t.erase(0,1);
        }
        if (s == t) return true;
        return false;
    }
}; 