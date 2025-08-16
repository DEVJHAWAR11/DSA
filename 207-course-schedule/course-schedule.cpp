class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];

        for(auto &e : prerequisites){
            int e1=e[1],e2=e[0];
            adj[e1].push_back(e2);
        }

        vector<int>indegree(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int temp=q.front();
            cnt++;
            q.pop();
            for(int i=0;i<adj[temp].size();i++){
                indegree[adj[temp][i]]--;
                if(indegree[adj[temp][i]]==0)
                    q.push(adj[temp][i]);
            }
        }
        return cnt==numCourses;
    }
};