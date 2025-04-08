class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        //brute force
        int maxArea=INT_MIN,currArea=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         area=min(height[i],height[j])*(j-i);
        //         maxArea=area>maxArea ? area : maxArea;
        //     }
        // }

        //2 ptr
        int i=0,j=n-1;
        while(i<j){
            int currWidth=j-i;
            int currH=min(height[i],height[j]);
            currArea=currH*currWidth;
            maxArea=max(currArea,maxArea);
            height[i]>height[j] ? j-- : i++;
        }


        return maxArea;
    }
};