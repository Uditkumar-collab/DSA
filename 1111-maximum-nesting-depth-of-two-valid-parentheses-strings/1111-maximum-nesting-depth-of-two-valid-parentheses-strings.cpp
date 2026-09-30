class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result(seq.length());
        int depth = 0;
        
        for (int i = 0; i < seq.length(); ++i) {
            if (seq[i] == '(') {
               
                result[i] = depth % 2;
                depth++;
            } else {
               
                depth--;
                result[i] = depth % 2;
            }
        }
        
        return result;
    }
};