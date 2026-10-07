class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
       
        int left_removed = 0;
        int right_removed = 0;
        
        for (char c : s) {
            if (c == '(') {
                left_removed++;
            } else if (c == ')') {
                if (left_removed == 0) {
                    right_removed++;
                } else {
                    left_removed--;
                }
            }
        }
        
        vector<string> result;
        dfs(s, 0, left_removed, right_removed, result);
        return result;
    }
    
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            
           
            if (count < 0) return false;
        }
        return count == 0;
    }
    
    void dfs(string s, int start, int l, int r, vector<string>& result) {
        
        if (l == 0 && r == 0) {
            if (isValid(s)) {
                result.push_back(s);
            }
            return;
        }
        
        for (int i = start; i < s.length(); ++i) {

            if (i != start && s[i] == s[i - 1]) {
                continue;
            }
            
            if (s[i] == '(' || s[i] == ')') {
                string curr = s;
                curr.erase(i, 1); 
                
               
                if (r > 0 && s[i] == ')') {
                
                    dfs(curr, i, l, r - 1, result);
                } 
               
                else if (l > 0 && s[i] == '(') {
                    dfs(curr, i, l - 1, r, result);
                }
            }
        }
    }
};