class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>temp;
        for(int i=0;i<wordList.size();i++){
            temp.insert(wordList[i]);
        }
        if(temp.count(endWord)==0) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        temp.erase(beginWord);

        while(!q.empty()){
            string str=q.front().first;
            int level=q.front().second;
            q.pop();

            if(str==endWord) return level;
            for(int i=0;i<str.size();i++){
                char original=str[i];
                for(char ch ='a'; ch<='z';ch++){
                    //string newstr=str;
                    str[i]=ch;
                    if(temp.count(str)){
                        q.push({str,level+1});
                        temp.erase(str);
                    }
                }
                str[i]=original;
            }
        }
        return 0;
    }
};