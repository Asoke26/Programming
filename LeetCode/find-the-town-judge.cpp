Problem Link : https://leetcode.com/problems/find-the-town-judge/submissions/


class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        if(N==1) return 1; // Base Case
        
        vector< vector<int>> tracker(N+1,vector<int>(N+1,0));
        vector<int> counter(N+1,0);
        
        for(int i=0;i<trust.size();i++)
        {
            int x = trust[i][0];
            int y = trust[i][1];
            
            tracker[x][y]++;
            counter[y]++;
        }
        
        for(int i=0;i<counter.size();i++)
        {
            if(counter[i]==N-1)
            {
                bool rowCheck = rowChecker(tracker,i);
                if(rowCheck==true) return i; 
            }
        }
        
        return -1;
    }
    
    bool rowChecker(vector< vector<int>> &tracker, int row)
    {
        for(int i=0;i<tracker[row].size();i++)
            if(tracker[row][i]!=0) return false;
        
        return true;
    }
};