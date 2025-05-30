// class compare{
//     public:
//         bool operator()(pair<vector<int>,float>A,pair<vector<int>,float>B){
//             return A.second > B.second;
//         }
// };

// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {        
//         priority_queue<pair<vector<int>,float>,vector<pair<vector<int>,float>>,compare>minHeap;
//         for(auto i : points){
//             float dist=sqrt((pow(i[0],2)+pow(i[1],2)));
//             minHeap.push({i,dist});
//         }
//         vector<vector<int>>ans;
//         while(!minHeap.empty() && k>0){
//             auto top = minHeap.top();
//             minHeap.pop();
//             ans.push_back(top.first);
//             k--;
//         }
//         return ans;
//     }
// }; 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> maxHeap;
        for (auto& point : points) {
            double distance = sqrt(pow(point[0], 2) + pow(point[1], 2));
            maxHeap.push({distance, point});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};