class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0,j=0,ans=0;
        for(auto str : commands){
            if(str=="RIGHT")
                j++;
            else if(str=="UP")
                i--;
            else if(str=="DOWN")
                i++;
            else 
                j--;
            ans=i*n+j;
        }
        return ans;
    }
};