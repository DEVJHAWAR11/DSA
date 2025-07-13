class Solution {
public:
    bool isSafe(int col,int row,vector<vector<bool>>board,int n){
        int tempRow=row,tempCol=col;

        while(row>=0 && col>=0){
            if(board[row][col]) return false;
            row--,col--;
        }

        row=tempRow,col=tempCol;
        while(col>=0){
            if(board[row][col]) return false;
            col--;
        }

        row=tempRow,col=tempCol;
        while(row<n && col>=0){
            if(board[row][col]) return false;
            row++,col--;
        }

        return true;
    }

    void solve(int col,vector<vector<bool>>&board,int &count,int n){
        if(col==n){
            count++;
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(col,row,board,n)){ 
                board[row][col]=true;
                solve(col+1,board,count,n);
                board[row][col]=false;
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<bool>>board(n,vector<bool>(n,false));
        int count=0;
        solve(0,board,count,n);
        return count;
    }
};

    


