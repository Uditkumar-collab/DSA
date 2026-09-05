class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> suffix_min(n);
        suffix_min[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            suffix_min[i] = min(suffix_min[i + 1], nums[i]);
        }
        
        int current_max = -1;
        
        for (int i = 0; i < n; ++i) {
            current_max = max(current_max, nums[i]);
            
            if (current_max - suffix_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};