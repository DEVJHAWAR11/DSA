class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            int temp=i,flag=0;
            while(temp){
                int digit=temp%10;
                if(digit==0 || i%digit!=0)
                        flag=1;    
                temp=temp/10;
            }
            if(flag==0)
                ans.push_back(i);
        }
        return ans;
    }
};