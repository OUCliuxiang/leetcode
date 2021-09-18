#include <cstdio>
#include <string>

int main(){
    std::string s = "abcabcbb";
    int res = 0;
    std::string sub = "";
    for (int i = 0; i < s.length(); i++){
        printf("%d",i);
        if (i == s.length()-1)
            break;
        int len = res;
        while (sub.find(s[i]) == -1){
            sub += s[i++];
            len ++;
            res = (len > res ? len : res);
            // printf("%s",sub);
        }                        
        i = i + 1 - sub.length() + sub.find(s[i]);
        sub = s.substr(i, len-sub.find(s[i]));
        
    }
    return 0;
}