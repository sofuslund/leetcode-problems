class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        for i, c in enumerate(max(strs, key=len)):
            for s in strs:
                if i >= len(s):
                    return result
                elif s[i] != c:
                    return result
            result += c
        return result
