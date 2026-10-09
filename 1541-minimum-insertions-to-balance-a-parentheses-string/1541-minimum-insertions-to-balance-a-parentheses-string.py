class Solution:
    def minInsertions(self, s: str) -> int:
        insertions = 0
        need_right = 0
        
        for char in s:
            if char == '(':
                if need_right % 2 != 0:
                    insertions += 1
                    need_right -= 1
                
                need_right += 2
                
            else:
                need_right -= 1
                
                if need_right < 0:
                    insertions += 1
                    need_right += 2
                    
        return insertions + need_right