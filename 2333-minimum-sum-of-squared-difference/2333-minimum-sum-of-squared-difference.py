class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        k = k1 + k2
        
        diffs = [abs(a - b) for a, b in zip(nums1, nums2)]
       
        if sum(diffs) <= k:
            return 0       
       
        max_diff = max(diffs)
        
        counts = [0] * (max_diff + 1)
        for diff in diffs:
            counts[diff] += 1
            
        for i in range(max_diff, 0, -1):
            if counts[i] > 0:
                if k >= counts[i]:
                    k -= counts[i]
                    counts[i - 1] += counts[i]
                    counts[i] = 0
                else:
                    counts[i - 1] += k
                    counts[i] -= k
                    k = 0
                    break      
        ans = 0
        for i in range(max_diff, 0, -1):
            if counts[i] > 0:
                ans += counts[i] * (i * i)
                
        return ans