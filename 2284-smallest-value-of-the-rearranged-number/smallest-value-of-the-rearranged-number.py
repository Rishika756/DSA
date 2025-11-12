class Solution:
    def smallestNumber(self, num: int) -> int:
        if num == 0:
            return 0
        
        digits = list(str(abs(num)))
        
        if num < 0:
            digits.sort(reverse=True)
            return -int(''.join(digits))
        else:
            digits.sort()
            if digits[0] != '0':
                return int(''.join(digits))
            else:
                for i in range(1, len(digits)):
                    if digits[i] != '0':
                        digits[0], digits[i] = digits[i], digits[0]
                        break
                return int(''.join(digits))



       
        