// Problem Link : https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size()==0) return 0; // Base case for checking empty matrix
        
        int M=matrix.size();
        int N=matrix[0].size();        
        
        int max_sqr = 0; 
        
        vector<vector<int>> DP(2,vector<int>(N+1));
        
        bool flag = 0;
        
        for(int i=0;i<=M;i++)
        {
            for(int j=0;j<=N;j++)
            {
                if(i==0 || j==0) DP[flag][j] = 0;
                else if(matrix[i-1][j-1] == '1') 
                {
                    DP[flag][j] = min(min(DP[flag^1][j],DP[flag^1][j-1]),DP[flag][j-1]) + 1; 
                    if(DP[flag][j]>max_sqr) max_sqr=DP[flag][j];
                }
                else DP[flag][j] = 0;
            }
            flag^=1;
        }
        
        
        
        
        return pow(max_sqr,2);
    }
};
