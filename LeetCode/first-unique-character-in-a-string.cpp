Problem Link : https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> char_cnt;
        
        for(int i=0;i<s.size();i++) char_cnt[s[i]]++;
        
        for(int i=0;i<s.size();i++) if(char_cnt[s[i]]==1) return i;
        
        
        return -1;
        
    }
};
