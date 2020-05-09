Problem Link : https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        // Slope = (Y2-Y1)/(X2-X1)
        
        float slope = float(coordinates[1][1]-coordinates[0][1])/float(coordinates[1][0]-coordinates[0][0]);
        for(int i=1;i<coordinates.size()-1;i++)
        {
            float cur_slope = float(coordinates[i+1][1]-coordinates[i][1])/float(coordinates[i+1][0]-coordinates[i][0]);
            if(cur_slope != slope) return false;
        }
        
        return true;
    }
};