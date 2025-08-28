class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e8));

        for(auto e : edges){
            int u=e[0],v=e[1], w=e[2];
            dist[u][v]=w;
            dist[u][u]=0;
            dist[v][v]=0;
            dist[v][u]=w;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==k || j==k) continue;
                    if(dist[i][k]==1e8 || dist[k][j]==1e8) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold)
                ans[i]++;
            }
        }
        int mini=INT_MAX,node=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]<=mini){
                mini=ans[i];
                node=i;
            }
        }
        return node;    
    }
};