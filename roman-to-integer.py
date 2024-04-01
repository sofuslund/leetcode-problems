class Solution:
    def romanToInt(self, s: str) -> int:
        romanValues = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        number = 0
        for i, c in enumerate(s):
            if len(s)>i+1 and c in ("I", "X", "C") and s[i+1] in (list(romanValues.keys())[[*romanValues].index(c)+1], list(romanValues.keys())[[*romanValues].index(c)+2]):
                number -= romanValues[c]
            else:
                number += romanValues[c]

        return number
