class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int index = 0;
        set<string> result_set = parse(expression, index);
        return vector<string>(result_set.begin(), result_set.end());
    }

private:
    set<string> parse(const string& s, int& i) {
        set<string> res;          
        set<string> cur = {""};    

        while (i < s.length()) {
            if (s[i] == '{') {
                i++; // Skip '{'
                set<string> sub = parse(s, i);
                set<string> next_cur;
                
                
                for (const string& a : cur) {
                    for (const string& b : sub) {
                        next_cur.insert(a + b);
                    }
                }
                cur = next_cur;
            } else if (s[i] == '}') {
                i++; // Skip '}'
            
                for (const string& a : cur) res.insert(a);
                return res;
            } else if (s[i] == ',') {
                i++; // Skip ','
              
                for (const string& a : cur) res.insert(a);
                cur = {""};
            } else {
              
                set<string> next_cur;
                for (const string& a : cur) {
                    next_cur.insert(a + s[i]);
                }
                cur = next_cur;
                i++;
            }
        }
        
        for (const string& a : cur) res.insert(a);
        return res;
    }
};