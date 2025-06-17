class Solution {
public:
    void reverseString(vector<char>& s) {
        // Base case: empty or single-character string
        if (s.size() <= 1) return;

        // Induction step: save first character
        char ch = s[0];
        
        // Hypothesis: reduce problem size by one
        s.erase(s.begin());  // Remove first character (now size = n-1)
        reverseString(s);    // Reverse the smaller string
        
        // Induction: append original first character to end
        s.push_back(ch);
    }
};
