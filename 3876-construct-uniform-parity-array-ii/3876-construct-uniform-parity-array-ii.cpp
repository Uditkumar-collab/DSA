class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = INT_MAX; 
        bool has_odd = false;
        
        for (int num : nums1) {
            if (num < min_val) {
                min_val = num;
            }
            if (num % 2 != 0) {
                has_odd = true;
            }
        }
        
        return (min_val % 2 != 0) || !has_odd;
    }
};