Problem Link : https://leetcode.com/problems/valid-perfect-square/

class Solution {
public:
    bool isPerfectSquare(int num) {
        
        for(unsigned int i=1;i*i<=num;i++)
        {
            if(i*i==num) return true;
            else if(i*i>num) return false;
        }
        
        return false;
    }
};