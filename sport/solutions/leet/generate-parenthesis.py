class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def dfs(left, to_close, cur):
            if left < 0 or to_close < 0:
                return
            if left == 0 and to_close == 0:
                ans.append(''.join(cur))
                return
            
            # 1. add (
            if left > 0:
                cur.append('(')
                dfs(left-1, to_close+1, cur)
                cur.pop()
                
            if to_close > 0:
                cur.append(')')
                dfs(left,to_close-1,cur)
                cur.pop()
            return
        
        dfs(n, 0, [])
        return ans