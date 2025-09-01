class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n);
        for(auto v : bookings){
            int booking=v[2];
            for(int i=v[0];i<=v[1];i++){
                ans[i-1]+=booking;
            }
        }
      return ans;  
    }
};