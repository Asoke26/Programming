// Problem Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int M = s.size();
        int N = p.size();
        
        
        unordered_map<char,int> char_map; // Map and temporary map
        
        for(int i=0;i<p.size();i++) // Convert frequency of characters in p to map
            char_map[p[i]]++;
        
        vector<int> starting_indexs;
        
        for(int i=0;i<=M-N;i++)
        {
            string tempStr = s.substr(i, N);
            // cout<<"Temp string "<<tempStr<<endl;
            bool result = ifMatch(tempStr,char_map); // Check if tempString is an anagram of P
            
            if(result == true) starting_indexs.push_back(i);
            
        }
        
        return starting_indexs;
        
    }
    
    bool ifMatch(string tempStr,unordered_map<char,int> char_map)
    {
        int c = tempStr.size();
        
        for(int i=0;i<tempStr.size();i++)
        {
            if(char_map[tempStr[i]])
            {
                char_map[tempStr[i]]--;
                c--;
            }
        }
        
        return (c==0);
    }
};