class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();
        int delCol = 0;

        for (int j = 0; j < col; j++) { // for each column
            for (int i = 0; i < row - 1; i++) { // compare adjacent rows
                if (strs[i + 1][j] < strs[i][j]) {
                    delCol++;
                    break; // no need to check this column further
                }
            }
        }

        return delCol;
    }
};
