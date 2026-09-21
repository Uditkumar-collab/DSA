#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
      
        vector<long long> result(k, 0);
        
        
        vector<long long> dp(k, 0);
        
        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            long long val = num % k;
            
           
            for (int j = 0; j < k; ++j) {
                if (dp[j] > 0) {
                    next_dp[(j * val) % k] += dp[j];
                }
            }
            
           
            next_dp[val] += 1;
            
            
            for (int j = 0; j < k; ++j) {
                result[j] += next_dp[j];
            }
            
          
            dp = next_dp;
        }
        
        return result;
    }
};