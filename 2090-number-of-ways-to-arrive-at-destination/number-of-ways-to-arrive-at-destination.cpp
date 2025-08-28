class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : roads){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue; // outdated entry

            for(auto &[neigh, w] : adj[node]){
                long long newDist = d + w;

                if(newDist < dist[neigh]){
                    dist[neigh] = newDist;
                    pq.push({newDist, neigh});
                    ways[neigh] = ways[node];
                }
                else if(newDist == dist[neigh]){
                    ways[neigh] = (ways[neigh] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;
    }
};
