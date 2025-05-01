class Solution {
private:
    queue<int>q;
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int>ans(deck.size());
        sort(deck.begin(),deck.end());

        for(int i=0;i<ans.size();i++)
            q.push(i);
        
        for(int i=0;i<deck.size();i++){

            ans[q.front()]=deck[i];
            q.pop();

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;

    }
};