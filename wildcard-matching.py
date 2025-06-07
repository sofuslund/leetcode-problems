class Solution:        
    def isMatch(self, s: str, p: str) -> bool:
        if len(s) == 0:
            return all(c == '*' for c in p)
        if len(p) == 0:
            return False
        matrix = [[False for col in range(len(s))] for row in range(len(p))]
        min_col = 0
        for row in range(len(p)):
            first_path_encountered = False
            tmp = min_col
            if p[row] == '*' and min_col > 0:
                tmp = min_col-1
            for col in range(tmp, len(s)):
                if (s[col] == p[row] or p[row] == '?') and (col == 0 or (col > 0 and row > 0 and matrix[row-1][col-1])):
                    if not first_path_encountered:
                        min_col = col+1
                        first_path_encountered = True
                        if min_col == len(s):
                            for i in range(row+1, len(p)):
                                if (p[i] != '*'):
                                    return False
                            return True
                    matrix[row][col] = True
                elif (p[row] == '*'):
                    matrix[row][col] = True
            if p[row] != '*' and not first_path_encountered:
                print(row, 'HEY')
                return False
        print(matrix)
        return matrix[len(p)-1][len(s)-1]
