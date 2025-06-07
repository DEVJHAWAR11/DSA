class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        L=s.split(' ')
        L.reverse()
        s=' '.join(L)
        clean_s=' '.join(s.split())
        return clean_s

        