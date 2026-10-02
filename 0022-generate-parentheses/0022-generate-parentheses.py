class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []
        
        def backtrack(open_count: int, close_count: int, current_string: str):
           
            if len(current_string) == 2 * n:
                result.append(current_string)
                return
            
            
            if open_count < n:
                backtrack(open_count + 1, close_count, current_string + "(")
                
            
            if close_count < open_count:
                backtrack(open_count, close_count + 1, current_string + ")")
                
        backtrack(0, 0, "")
        return result