import sys
class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
    	result = 0;
    	if x > 0:
    		result = int(str(x)[::-1])
        elif x == 0:
        	return 0
        else:
        	result = -1 * int(str(x*-1)[::-1])

        #if (result > sys.maxint) or (result < -sys.maxint - 1):
        if (result > 2147483647) or (result < -2147483648):
        	result = 0
        return result

s = Solution()
print s.reverse(123)
print s.reverse(-123)
print s.reverse(0)
