// class Solution {
// public:
//     int maxBalancedShipments(vector<int>& weight) {
//         int count=0;
//         int i=0,j=1,maxi=0;
//         while(i<j && j < weight.size()){
//             if(weight[i] <= weight[j]){
//                 maxi=max(maxi,weight[j]);
//                 i++,j++;
//             }
//             else{
//                 count++;
//                 maxi=0;
//                 i+=2,j+=2;
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int shipment = 0;
        for(int i = 0; i < weight.size() - 1; i++){
            if(weight[i] > weight[i+1]){
                shipment++;
                i++;
            }
        }
        return shipment;
    }
};