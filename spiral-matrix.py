class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # start: top side, spiral: clockwise
        lst = [] # return list
        sides = [0, len(matrix[0])-1, len(matrix)-1, 0] # top, right, bottom, left
        dirs = ((1, 0), (0, 1), (-1, 0), (0, -1))
        pos = [0, 0]
        count = 0 # increments each turn, count%4 = current side
 
        while (sides[2] - sides[0]) >= 0 and (sides[1] - sides[3]) >= 0:
            lst.append(matrix[pos[1]][pos[0]])
            # if next corner is encountered i.e. relevant coordinate (either x or y) equals next side bound
            if abs(pos[0]*dirs[count%4][0]+pos[1]*dirs[count%4][1]) == sides[(count+1)%4]:
                sides[count%4] += abs(count%4-1.5)*2-2 # move side via math trick: +1 for 0 and 3, -1 for 1 and 2
                count += 1 # increment side counter
            pos[0] += dirs[count%4][0]
            pos[1] += dirs[count%4][1]

        return lst