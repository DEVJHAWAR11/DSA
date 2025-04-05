class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans="";int i=0;
        sort(strs.begin(),strs.end());
        string first = strs[0], last = strs[strs.size()-1];

        while(i<first.size()){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
            i++;
        }

        // while(i<strs[0].size()){
        //     for(auto str : strs){
        //         if(str[i]!=strs[0][i]){
        //             return ans;
        //         }
        //     }
        //     ans+=strs[0][i];
        //     i++;
        // }
        return ans;
    }
};