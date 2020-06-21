class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        // Variables
        int no_of_rows = board.size();
        if(no_of_rows==0) return;
        
        int no_of_cols = board[0].size();
        
        cout<<no_of_rows<<" &&& "<<no_of_cols<<endl;
        vector <vector <int>> visited(no_of_rows,vector<int> (no_of_cols,-1));

        
        // Top level 'O' traversal
        for(int j=0;j<no_of_cols;j++){
            if(board[0][j] == 'O') BFS(0,j,board,visited);

        // Bottom level 'O' traversal
        for(int j=0;j<no_of_cols;j++){
            if(board[no_of_rows-1][j] == 'O') BFS(no_of_rows-1,j,board,visited);
        }

        // Left level 'O' traversal
        for(int i=0;i<no_of_rows;i++){
            if(board[i][0] == 'O') BFS(i,0,board,visited);
        }      

        // Right level 'O' traversal
        for(int i=0;i<no_of_rows;i++){
            if(board[i][no_of_cols-1] == 'O') {
                BFS(i,no_of_cols-1,board,visited);
            }
            
            
        }
        
        
        FLIP(visited,board);
    }
    
    void BFS(int i, int j, vector<vector<char>>& board ,vector <vector <int>> &visited)
    {
        
         // Variables
        int no_of_rows = board.size();        
        int no_of_cols = board[0].size();
        
        stack <pair<int,int>> STACK;        
        STACK.push(make_pair(i,j));
        visited[i][j] = 1;

        
        while(!STACK.empty()){
            pair<int,int> current_element = STACK.top();
            int ii = current_element.first;
            int jj = current_element.second;            
            STACK.pop();
            
            
            // Up Move
            if(ii-1 > 0 && board[ii-1][jj] == 'O' && visited[ii-1][jj] == -1){
                STACK.push(make_pair(ii-1,jj));
                visited[ii-1][jj] = 1;
            }
            
            // Down Move            
            if(ii+1 < no_of_rows && board[ii+1][jj] == 'O' && visited[ii+1][jj] == -1){
                STACK.push(make_pair(ii+1,jj));
                visited[ii+1][jj] = 1;
            }
            
            // Left move
            if(jj-1 > 0 && board[ii][jj-1] == 'O' && visited[ii][jj-1] == -1){
                STACK.push(make_pair(ii,jj-1));
                visited[ii][jj-1] = 1;
            }
            
            // Right Move
            if(jj+1 < no_of_cols && board[ii][jj+1] == 'O' && visited[ii][jj+1] == -1)
            {
                STACK.push(make_pair(ii,jj+1));
                visited[ii][jj+1] = 1;

            }
            
            
        }
        
    }
    
    void FLIP(vector <vector <int>> &visited, vector<vector<char>>& board)
    {
        for(int i=0;i<visited.size();i++){
            for(int j=0;j<visited[i].size();j++)
            {
                if(visited[i][j] == -1 && board[i][j] == 'O') board[i][j] = 'X'; 
            }
        }
    }
    
    void PRINT(vector <vector <int>> &visited )
    {
        for(int i=0;i<visited.size();i++){
            for(int j=0;j<visited[i].size();j++)
            {
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};