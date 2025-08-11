class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
    
        vector<int> powers;
        for (int i = 0; i < 31; ++i) {
            if (n & (1 << i)) {
                powers.push_back(1 << i);
            }
        }
        
    
        vector<long long> prefix(powers.size() + 1, 1);
        for (int i = 0; i < powers.size(); ++i) {
            prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
        }
        
        
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long product = (prefix[r + 1] * modInverse(prefix[l], MOD)) % MOD;
            ans.push_back((int)product);
        }
        
        return ans;
    }

private:
    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    long long modInverse(long long a, int mod) {
        return modPow(a, mod - 2, mod); 
    }
};
