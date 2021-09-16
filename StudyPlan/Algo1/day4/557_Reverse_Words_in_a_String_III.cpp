class Solution {
public:
    string reverseWords(string s) {
        int found = 0;
        while (found != -1){
            int wordeEnd = s.find_first_of(' ', found + 1);
            reverse(s.begin()+found, s.begin()+wordEnd);
            found = wordEnd();
        } 
    }
};