class compare{
    public:
        bool operator()(pair<int,int>a,pair<int,int>b){
            return a.second < b.second;
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto i : nums){
            mpp[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        for(auto i : mpp){
            pq.push(i);
        }
        vector<int>ans;
        while(!pq.empty() && k--){
            auto top=pq.top();
            pq.pop();
            ans.push_back(top.first);
        }
        return ans;
    }
};