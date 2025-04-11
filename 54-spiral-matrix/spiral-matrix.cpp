class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int startRow=0;
        int endRow=m-1;
        int startCol=0;
        int endCol=n-1;
        int count=0;
        while(count<m*n){
             for(int i=startCol;i<=endCol && count<m*n;i++){
            ans.push_back(matrix[startRow][i]);
            count++;
        }
        startRow++;
        for(int i=startRow;i<=endRow  && count<m*n;i++){
            ans.push_back(matrix[i][endCol]);
            count++;
        }
        endCol--;
        for(int i=endCol;i>=startCol  && count<m*n;i--){
            ans.push_back(matrix[endRow][i]);
            count++;
        }
        endRow--;
        for(int i=endRow;i>=startRow  && count<m*n;i--){
            ans.push_back(matrix[i][startCol]);
            count++;
        }
        startCol++;
        }
       
   return ans;
    }
    
};