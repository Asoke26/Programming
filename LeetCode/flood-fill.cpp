Problem link : https://leetcode.com/problems/flood-fill/submissions/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int M = image.size();
        int N = image[0].size();
        
        pair<int,int> coordinate;
        stack< pair<int,int> > STACK;
        vector<vector<bool>> visited(M,vector<bool>(N,0));
        
        STACK.push(make_pair(sr,sc));
        int originalColor = image[sr][sc];
        image[sr][sc] = newColor;
        visited[sr][sc] = 1;
        
        while(!STACK.empty())
        {
            pair<int,int> temp = STACK.top();
            int x = temp.first;
            int y = temp.second;
            visited[x][y] = 1;
            cout<<x<<y<<endl;
            STACK.pop();
            
            if(y-1 >=0) { // Left
                if(image[x][y-1] == originalColor && visited[x][y-1] == 0) 
                {
                    image[x][y-1] = newColor;
                    STACK.push(make_pair(x,y-1));
                }
                
            }
            
            if(y+1 <N) { // Right
                if(image[x][y+1] == originalColor && visited[x][y+1] == 0) {
                    image[x][y+1] = newColor;
                    STACK.push(make_pair(x,y+1));
                }
                
            }
            
            if(x-1 >=0) { // Up
                if(image[x-1][y] == originalColor && visited[x-1][y] == 0)
                {
                    image[x-1][y] = newColor;
                    STACK.push(make_pair(x-1,y));
                }
                
            }
            
            if(x+1 < M) { //Down
                if(image[x+1][y] == originalColor && visited[x+1][y] == 0){
                    image[x+1][y] = newColor;  
                    STACK.push(make_pair(x+1,y));
                } 
                
            }
            
        }
        
        return image;
    }
};