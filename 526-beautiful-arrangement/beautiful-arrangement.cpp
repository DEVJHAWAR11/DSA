// class Solution {
// public:
//     int solve(vector<vector<int>>&per){
//         int count=0;
//         for(auto permu : per){
//             int flag=0;
//             for(int i=0;i<permu.size();i++){
//                 if(permu[i]%(i+1)==0 || (i+1)%permu[i]==0)
//                     continue;
//                 else
//                     flag=1;
//             }
//             if(flag==0)
//                 count++;
//         }
//         return count;
//     }

//     void permutations(vector<int>&path,vector<bool>&used,vector<vector<int>>&per,int n){
//         if(path.size()==n){
//             per.push_back(path);
//             return;
//         }
//         for(int i=0;i<n;i++){
//             if(used[i]) continue;
//             used[i]=true;
//             path.push_back(i+1);
//             permutations(path,used,per,n);
//             path.pop_back();
//             used[i]=false;
//         }
//     }

//     int countArrangement(int n) {
//         vector<vector<int>>per;
//         vector<bool>used(n,false);
//         vector<int>path;
//         permutations(path,used,per,n);
//         int ans=solve(per);
//         return ans;
//     }
// };

class Solution {
public:
    int count = 0;

    void permutations(vector<int>& path, vector<bool>& used, int n) {
        if (path.size() == n) {
            count++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;

            int pos = path.size() + 1;         // 1-based position
            int val = i + 1;                   // actual number to place

            if (val % pos != 0 && pos % val != 0)
                continue;                      // pruning: skip invalid placements

            used[i] = true;
            path.push_back(val);
            permutations(path, used, n);
            path.pop_back();
            used[i] = false;
        }
    }

    int countArrangement(int n) {
        vector<bool> used(n, false);
        vector<int> path;
        permutations(path, used, n);
        return count;
    }
};
