class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        
        if (m + n - 1) % 2 != 0:
            return False
        
        if grid[0][0] == ')' or grid[m - 1][n - 1] == '(':
            return False
            
        @lru_cache(None)
        def dfs(r: int, c: int, balance: int) -> bool:
          
            if grid[r][c] == '(':
                balance += 1
            else:
                balance -= 1
                
            
            if balance < 0:
                return False
                
            
            if r == m - 1 and c == n - 1:
                return balance == 0
                
            valid = False
            if r + 1 < m:
                valid = valid or dfs(r + 1, c, balance)
            if not valid and c + 1 < n:
                valid = valid or dfs(r, c + 1, balance)
                
            return valid

        return dfs(0, 0, 0)