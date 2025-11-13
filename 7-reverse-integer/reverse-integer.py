class Solution:
    def reverse(self, x: int) -> int:
        s=str(x)
        if x<0:
            res=-int("".join(reversed(s[1:])))
            
        else:
            res=int("".join(reversed(s)))
            

        if res < -2**31 or res > 2**31 - 1:
            return 0
        return res
        

        