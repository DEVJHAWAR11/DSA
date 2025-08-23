class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&disc,vector<int>&low,int &count,vector<vector<int>>&bridges,vector<int>&vis){
        vis[node]=1;
        disc[node]=low[node]=count;

        for(int i=0;i<adj[node].size();i++){
            int neighbour=adj[node][i];
            if(neighbour==parent) continue;  //prev edge ignore
            else if(vis[neighbour]==1){
                //back edge
                //update low
                low[node]=min(low[node],low[neighbour]);
            }
            else{
                //vis!=1 && neigh!=parent  --->tree edge
                count++;
                dfs(neighbour,node,adj,disc,low,count,bridges,vis);
                //update low while going back as well
                low[node]=min(low[node],low[neighbour]);
                //check for bridge
                if(disc[node] < low[neighbour]){
                    bridges.push_back({node,neighbour});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto e : connections){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>disc(n);
        vector<int>low(n);
        int count=0;
        vector<vector<int>>bridges;
        vector<int>vis(n,0);
        dfs(0,-1,adj,disc,low,count,bridges,vis);

        return bridges;

    }
};