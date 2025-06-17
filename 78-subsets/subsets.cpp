// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>temp;
//         for(int num=0;num<(1<<nums.size());num++){
//             temp={};
//             for(int i=0;i<nums.size();i++){
//                 if(num&(1<<i))
//                     temp.push_back(nums[i]);
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void solve(vector<int>ip,vector<int>op,vector<vector<int>>&res){
        if(ip.size()==0){
            res.push_back(op);
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin());

        solve(ip,op1,res);
        solve(ip,op2,res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(nums,op,ans);
        return ans;
        
    }
};