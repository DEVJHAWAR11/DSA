class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        queue<int>q;

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int temp=q.front();
                    q.pop();
                    for(int i=0;i<graph[temp].size();i++){
                        if(color[graph[temp][i]]==-1){
                            color[graph[temp][i]]=!color[temp];
                            q.push(graph[temp][i]);
                        }
                        else{
                            if(color[graph[temp][i]]==color[temp])
                                return false;
                            else
                                continue;
                        }
                    }
                }
            }   
        }  
        return true;
    }
};