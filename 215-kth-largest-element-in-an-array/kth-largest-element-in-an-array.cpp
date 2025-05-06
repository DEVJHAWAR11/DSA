class Solution {
private:
    priority_queue<int>pq;
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(auto i : nums){
            pq.push(i);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};