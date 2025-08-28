class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //need minimum time till all the nodes have been visited ...as we are finding the shortest path for each node from k so the total time would e the maximum time inthe dist array 
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int ans=INT_MIN;
        for(auto e : times){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
        }

        pq.push({0,k});
        dist[k]=0;

        while(!pq.empty()){
            auto temp=pq.top();
            int time=temp.first;
            int node=temp.second;
            pq.pop();

            for(int i=0;i<adj[node].size();i++){
                int t=adj[node][i].second;
                int neighbour=adj[node][i].first;

                if(time + t < dist[neighbour]){
                    dist[neighbour]=time+t;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};