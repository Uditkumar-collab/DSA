class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        long long power_of_10 = 1000;
        
        while (n >= power_of_10) {
            total_commas += (n - power_of_10 + 1);
            power_of_10 *= 1000;
        }
        
        return total_commas;
    }
};