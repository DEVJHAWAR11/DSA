// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int>ans;
//         queue<int>q;
//         int i=0,j=0;
//         while(j < nums.size()){
//             while(!q.empty() && nums[j]>q.front())  q.pop();

//             q.push(nums[j]);

//             if( j-i+1 < k)  j++;

//             else if (j-i+1 == k){
//                 ans.push_back(q.front());
//                 if(nums[i]==q.front())
//                     q.pop();
//                 i++,j++;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int i=0,j=0;
        while(j < nums.size()){
            while(!dq.empty() && nums[j]>dq.back())  dq.pop_back();

            dq.push_back(nums[j]);

            if( j-i+1 < k)  j++;

            else if (j-i+1 == k){
                ans.push_back(dq.front());
                if(nums[i]==dq.front())
                    dq.pop_front();
                i++,j++;
            }
        }
        return ans;
    }
};