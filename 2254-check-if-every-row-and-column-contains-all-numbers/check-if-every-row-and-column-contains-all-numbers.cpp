class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int>unique;
        for(int i=0 ;i< n;i++){
            for(int j=0;j<n;j++){
                unique.insert(matrix[i][j]);
            }
            if(unique.size()!=n) return false;
            unique.clear();
        }

        for(int i=0 ;i<n;i++){
            for(int j=0;j<n;j++){
                unique.insert(matrix[j][i]);
            }
            if(unique.size()!=n) return false;
            unique.clear();
        }
        return true;
    }
};