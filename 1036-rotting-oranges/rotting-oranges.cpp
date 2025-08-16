class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]==2)
                    q.push({i,j});
        int timer=0;
        while(!q.empty()){
            int curr_pos=q.size();
            bool rot=false;
            while(curr_pos--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                int dx[4]={0,0,1,-1};
                int dy[4]={1,-1,0,0};
                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];

                    if(ni>=0 && ni<r && nj>=0 && nj<c && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                        rot=true;   
                    }
                }
            }
            if(rot) timer++;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return timer;
    }
};