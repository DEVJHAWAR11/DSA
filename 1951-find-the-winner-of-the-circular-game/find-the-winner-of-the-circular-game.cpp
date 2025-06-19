// class Solution {
// private:
//     queue<int>q;
// public:
//     int findTheWinner(int n, int k) {

//         for(int i=1;i<=n;i++){
//             q.push(i);
//         }
        
//         while(q.size()!=1){

//             for(int i=1;i<k;i++){
//                 q.push(q.front());
//                 q.pop();
//             }

//             q.pop();
//         }

//         return q.front();
//     }
// };

class Solution {
public:
    int solve(vector<int>&temp,int k,int index){
        if(temp.size()==1)
            return temp[0];

        index=(index+k-1)%temp.size();
        temp.erase(temp.begin()+index);

        return solve(temp,k,index);
    }

    int findTheWinner(int n, int k) {
        vector<int>temp;
        for(int i=1;i<=n;i++)
            temp.push_back(i);
        return solve(temp,k,0);
    }
};