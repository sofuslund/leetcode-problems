class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # Alternative solution: return len(re.search("(\S*)\s*$", s).group(1))
        l = 0
        i = len(s)-1
        while i >= 0 and s[i] == ' ':
            i -= 1
        while i >= 0 and s[i] != ' ':
            l += 1
            i -= 1
        return l
