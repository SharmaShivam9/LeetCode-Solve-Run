class Solution {
private:
    int bfs(int a,int b,vector<vector<char>>&grid,vector<vector<int>>&visited){
        queue <pair<int,int>> q;
        q.push({a,b});
        while(!q.empty()){
            int cr=q.front().first;
            int cc=q.front().second;
            q.pop();
            int m=grid.size();
            int n=grid[0].size();
            vector <int> dr={-1,1,0,0};
            vector <int> dc={0,0,-1,1};
            for (int i=0;i<4;++i){
                    int row=cr+dr[i];
                    int col=cc+dc[i];
                    if(row>=0 && row<m && col>=0 && col<n && grid[row][col]=='1' && visited[row][col]==0){
                        q.push({row,col});
                        visited[row][col]=1;
                    }
                    
                }
        }
        return 1;
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        int islands=0;
        
        for (int i=0;i<m;++i){
            for (int j=0;j<n;++j){
                if (grid[i][j]=='1' && visited[i][j]==0){
                    visited[i][j]=1;
                    islands+=bfs(i,j,grid,visited);
                }}
                
        }
        return islands;
    }
};