class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int fresh=0;
        int min=0;
        queue <pair <int,int>> q;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        while(!q.empty() && fresh>0){
            int rotten=q.size();
            for (int i=0;i<rotten;i++){
                pair <int,int> curr=q.front();
                int cr=curr.first;
                int cc=curr.second;
                q.pop();

                int dr[]={-1,1,0,0};
                int dc[]={0,0,-1,1};

                for (int j=0;j<4;j++){
                    int nr=cr+dr[j];
                    int nc=cc+dc[j];
                    if (nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        q.push({nr,nc});
                        fresh--;
                        grid[nr][nc]=2;
                    }
                }
            }
            min++;
        }
        if (fresh>0){
            return -1;
        } 
        else{
            return min;
        }}
};