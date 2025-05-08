class compare{
    public:
        bool operator()(pair<vector<int>,float>A,pair<vector<int>,float>B){
            return A.second > B.second;
        }
};

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<vector<int>,float>>PairArr;
        float dist=0;
        for(auto i : points){
            dist=sqrt((pow(i[0],2)+pow(i[1],2)));
            PairArr.push_back({i,dist});
        }
        priority_queue<pair<vector<int>,float>,vector<pair<vector<int>,float>>,compare>minHeap;
        for(auto i : PairArr){
            minHeap.push(i);
        }
        vector<vector<int>>ans;
        while(!minHeap.empty() && k>0){
            auto top = minHeap.top();
            minHeap.pop();
            ans.push_back(top.first);
            k--;
        }
        return ans;
    }
};