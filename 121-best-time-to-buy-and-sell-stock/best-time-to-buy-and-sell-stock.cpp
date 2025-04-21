class Solution {
public:
    
    //recursive
    // void recursive(vector<int> prices,int i,int &currP,int &mini,int &maxP){
    //     //base case
    //     if(i==prices.size())
    //         return;

    //     currP=prices[i]-mini;
    //     maxP=max(maxP,currP);
    //     mini=min(mini,prices[i]);

    //     recursive(prices,i+1,currP,mini,maxP);

    // }

    int maxProfit(vector<int>& prices) {
        //bruteforce
        // int profit=0,ans=0;
        // for(int i=0;i<prices.size();i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         profit=prices[j]-prices[i];
        //         ans=max(ans,profit);
        //     }
        // }
        // if(ans>0)
        //     return ans;
        // else
        //     return 0;

        //m-2
        int mini=prices[0];   //need min buying price
        int currP=0;
        int maxP=0;
        for(int i=1;i<prices.size();i++){
            currP=prices[i]-mini;
            maxP=max(maxP,currP);
            mini=min(mini,prices[i]);
        }
        return maxP;

        //recurrsive
        // recursive(prices,1,currP,mini,maxP);
        // return maxP;



        

    }
};