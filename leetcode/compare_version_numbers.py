'''
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
'''
class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        list1 = [int(x) for x in version1.split(".")]
        list2 = [int(x) for x in version2.split(".")]
        
        l1 = len(list1)
        l2 = len(list2)
        mlength = max(l1, l2)
        
        for x in range(0,mlength):
            x1 = 0 if x+1 > l1 else list1[x]
            x2= 0 if x+1 > l2 else list2[x]
            #print list1[x], list2[x]
            if x1 > x2:
                return 1
            elif x1 < x2:
                return -1

        return 0

if __name__ == '__main__':
    s = Solution()
    print s.compareVersion("12.15","12.16")
    print s.compareVersion("12.15","12.15")
    print s.compareVersion("12.15","12.15.1")
    print s.compareVersion("12.15.1","12.15")