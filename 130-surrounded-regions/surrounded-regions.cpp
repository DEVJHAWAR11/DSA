class Solution {
public:

    void dfs(int i,int j,vector<vector<char>>&board,vector<vector<int>>&vis){
        vis[i][j]=1;

        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        int r=board.size(),c=board[0].size();

        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];

            if(ni>=0 && ni<r && nj>=0 && nj<c && board[ni][nj]=='O'&& vis[ni][nj]==-1)
                dfs(ni,nj,board,vis);
        }
    }

    void solve(vector<vector<char>>& board) {
        int r=board.size(),c=board[0].size();
        vector<vector<int>>cantBeX(r,vector<int>(c,-1));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || i==r-1 || j==0 || j==c-1){
                    if(board[i][j]=='O'){
                        cantBeX[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(cantBeX[i][j]==0){
                    dfs(i,j,board,cantBeX);
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(cantBeX[i][j]!=1 && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};