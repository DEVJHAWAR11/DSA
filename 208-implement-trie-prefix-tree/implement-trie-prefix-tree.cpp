class TrieNode{
    public:
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(){
            for(int i=0;i<26;i++){
                this->children[i]=NULL;
            }
            this->isTerminal=false;
        }
};


class Trie {
    TrieNode* root;
public:
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp=root;
        for(auto ch : word){
            int index=ch-'a';
            if(temp->children[index]==NULL)
                temp->children[index]=new TrieNode();
            temp=temp->children[index];
        }
        temp->isTerminal=true;
    }
    
    bool search(string word) {
        TrieNode* temp=root;
        for(auto ch : word){
            int index=ch-'a';
            if(temp->children[index]==NULL){
                return false;
            }
            temp=temp->children[index];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp=root;
        for(auto ch : prefix){
            int index = ch -'a';
            if(temp->children[index]==NULL){
                return false;
            }
            temp=temp->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */