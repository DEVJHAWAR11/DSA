class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto i : piles){
            pq.push(i);
        }
        while(k--){
            int temp=pq.top();
            pq.pop();
            pq.push((temp-floor(temp/2)));
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};