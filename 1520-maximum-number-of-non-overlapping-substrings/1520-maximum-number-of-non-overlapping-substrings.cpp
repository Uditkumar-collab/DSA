class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        
        vector<pair<int, int>> intervals;
        
        for (int i = 0; i < 26; ++i) {
            if (first[i] != -1) {
                int left = first[i];
                int right = last[i];
                bool valid = true;
                
                for (int j = left; j <= right; ++j) {
                    int c = s[j] - 'a';
                    if (first[c] < left) {
                        valid = false;
                        break;
                    }
                    right = max(right, last[c]);
                }
                
                if (valid) {
                    intervals.push_back({left, right});
                }
            }
        }
        
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        });
        
        vector<string> res;
        int last_R = -1;
        
        for (auto& p : intervals) {
            if (p.first > last_R) {
                res.push_back(s.substr(p.first, p.second - p.first + 1));
                last_R = p.second;
            }
        }
        
        return res;
    }
};