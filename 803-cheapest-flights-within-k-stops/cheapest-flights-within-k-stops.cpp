class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        queue<pair<int,pair<int,int>>>q;
        
        //vector<int>Explored(V,0);
        vector<int>dist(n,INT_MAX);

        for(auto v : flights){
            int e1=v[0],e2=v[1],e3=v[2];
            adj[e1].push_back({e2,e3});
        }
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            int node=q.front().second.first;
            int tempK=q.front().first;
            int cost=q.front().second.second;
            q.pop();

            if(tempK > k) continue;
            //if(Explored[node]) continue;

            //Explored[node]=1;

            for(int i=0;i<adj[node].size();i++){
                int neighbour=adj[node][i].first;
                int w=adj[node][i].second;


                if(cost+w < dist[neighbour] && tempK <= k){
                    dist[neighbour]=cost+w;
                    q.push({tempK+1,{neighbour,dist[neighbour]}});
                }
            }

        }  
        return dist[dst]==INT_MAX? -1 : dist[dst];
    }
};