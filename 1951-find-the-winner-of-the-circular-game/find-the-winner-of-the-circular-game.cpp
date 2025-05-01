class Solution {
private:
    queue<int>q;
public:
    int findTheWinner(int n, int k) {

        for(int i=1;i<=n;i++){
            q.push(i);
        }
        
        while(q.size()!=1){

            for(int i=1;i<k;i++){
                q.push(q.front());
                q.pop();
            }

            q.pop();
        }

        return q.front();
    }
};