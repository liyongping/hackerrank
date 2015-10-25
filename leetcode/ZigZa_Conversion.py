class Solution:
	# @param {string} s
	# @param {integer} numRows
	# @return {string}
	def convert(self, s, numRows):
		if numRows == 1:
			return s
		step_size = numRows*2-2
		result = ["" for x in range(0,numRows)]
		for i in range(0,len(s)):
			imod = i % step_size
			if imod < numRows:
				result[imod] += s[i]
			else:
				result[2*(numRows-1)-imod] += s[i]

		print result
		for r in range(0,numRows):
			print result[r]
		return "".join(result)

s = Solution()
s.convert("PAYPALISHIRING",3)
s.convert("ABCDEFGHIJKLMN",2)
s.convert("ABCDEFGHIJKLMN",5)
