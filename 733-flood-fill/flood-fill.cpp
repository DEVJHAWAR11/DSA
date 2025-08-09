class Solution {
public:
    void dfs(vector<vector<int>>&image,int sr,int sc,int color,int temp){
        image[sr][sc]=color;

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nsr=sr+dr[k];
            int nsc=sc+dc[k];

            if(nsr>=0 && nsr<image.size() && nsc>=0 && nsc<image[0].size()
               && image[nsr][nsc]==temp && image[nsr][nsc]!=color)
            dfs(image,nsr,nsc,color,temp);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int temp=image[sr][sc];
        dfs(image,sr,sc,color,temp);
        return image;
    }
};