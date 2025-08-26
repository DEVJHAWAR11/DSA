class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>revList(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                revList[graph[i][j]].push_back(i);
            }
        }
        queue<int>q;
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<revList[i].size();j++){
                indegree[revList[i][j]]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<revList[node].size();i++){
                indegree[revList[node][i]]--;
                if(!indegree[revList[node][i]]){
                    q.push(revList[node][i]);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};