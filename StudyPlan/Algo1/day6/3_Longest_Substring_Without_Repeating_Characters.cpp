class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int start = -1, maxLen = 0;
        for(int i = 0; i < s.length(); i++){
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }

    int lengthOfLongestSubstring_Modified(string s) {
        map<char, int> charMap;
        int start = -1, maxLen = 0;
        for(int i = 0; i < s.length(); i++){
            if (charMap.count(s[i]) != 0)
                start = max(charMap[s[i]], start);
                // 当前元素上一次出现的位置与上一组重复元素 
                // 倒数第二次出现的位置做个比较
            charMap[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};
