class compare{
    public:
    bool operator()(pair<char,int>a, pair<char,int>b){
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        pair<char,int>p,q;
        string ans="";

        //freq count of each char
        int freq[26]={0};
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            freq[ch-'a']++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        for(int i=0;i<26;i++){
            if(freq[i]){
                pq.push({i+'a',freq[i]});
            }
        }

        while(pq.size()>1){    //atleast 2 pairs needed since popping two 
            p=pq.top();
            pq.pop();
            q=pq.top();
            pq.pop();

            ans.push_back(p.first);
            p.second--;
            ans.push_back(q.first);
            q.second--;

            if(p.second) pq.push(p);
            if(q.second) pq.push(q);
        }

        // Handle last character, if any
        if (!pq.empty()) {
            p = pq.top(); pq.pop();
            if (p.second > 1) return "";  // ❗ Not possible to place
            ans.push_back(p.first);
        }

        return ans;
    }
};