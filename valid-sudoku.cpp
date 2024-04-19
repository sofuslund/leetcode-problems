#include <string>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int cols[9][9];
        int boxes[9][9];

        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(rows));
        memset(boxes, 0, sizeof(rows));
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << (i/3)*3 + j/3 << endl;
                if(board[i][j] == '.')
                    continue;
                int tmp = board[i][j]-'0'-1;
                if(++rows[i][tmp] > 1)
                    return false;
                if(++cols[j][tmp] > 1)
                    return false;
                if(++boxes[(i/3)*3 + j/3][tmp] > 1)
                    return false;
            }
        }
        return true;
    }
};
