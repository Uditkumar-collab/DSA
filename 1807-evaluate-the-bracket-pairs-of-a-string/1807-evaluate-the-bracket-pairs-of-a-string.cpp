class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
    
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string res;
        res.reserve(s.length()); 
        
        string current_key = "";
        bool in_bracket = false;
        
        
        for (char c : s) {
            if (c == '(') {
                in_bracket = true;
            } else if (c == ')') {
                in_bracket = false;
                
               
                auto it = dict.find(current_key);
                if (it != dict.end()) {
                    res += it->second;
                } else {
                    res += '?';
                }
                
               
                current_key.clear();
            } else {
                if (in_bracket) {
                    current_key += c;
                } else {
                    res += c;
                }
            }
        }
        
        return res;
    }
};