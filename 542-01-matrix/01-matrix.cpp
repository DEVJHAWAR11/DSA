class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int timer=1;
        while(!q.empty()){
            int curr_pos=q.size();
            bool flag = false;
            while(curr_pos--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                int dx[4]={0,0,1,-1};
                int dy[4]={1,-1,0,0};

                for(int k=0;k<4;k++){
                    int ni=dx[k]+i;
                    int nj=dy[k]+j;

                    if(ni>=0 && ni<m && nj>=0 && nj<n && mat[ni][nj]==1 && vis[ni][nj]==0){
                        vis[ni][nj]=1;
                        q.push({ni,nj});
                        dist[ni][nj]=timer;
                        flag=true;
                    }
                }
            }
            if(flag) timer++;
        }
        return dist;
    }
};