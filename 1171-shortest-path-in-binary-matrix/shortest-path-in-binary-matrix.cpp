class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        if(grid[0][0]==1||grid[row-1][col-1]==1) return -1;
        vector<vector<int>>dist(row,vector<int>(col,0));
        queue<pair<int,int>>q;

        q.push({0,0});
        dist[0][0]=1;
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){

                    int ni=i+k;
                    int nj=j+l;

                    if(ni>=0 && nj>=0 && ni<row && nj<col && !dist[ni][nj] && grid[ni][nj]!=1){
                        dist[ni][nj]=dist[i][j]+1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return dist[row-1][col-1]==0 ? -1 : dist[row-1][col-1];
    }
};