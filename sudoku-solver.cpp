class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int brd[9][9];
        int rows[9][9];
        int cols[9][9];
        int boxes[9][9];
        memset(brd, -1, sizeof(brd));
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxes, 0, sizeof(boxes));

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j]=='.') {
                    brd[i][j] = -1;
                    continue;
                }
                brd[i][j] = board[i][j]-'0'-1;

                int tmp = board[i][j]-'0'-1;
                rows[i][tmp]++;
                cols[j][tmp]++;
                boxes[(i/3)*3 + j/3][tmp]++;
            }
        }
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j< 9; j++) {
                // Skip if it's not a blank cell
                if(board[i][j]!='.')
                    continue;
                
                // See if we can put a number into the current cell
                int brd_before= brd[i][j];
                cout << "BRD BEFORE: " << brd_before+1 << endl;
                for(int k = (brd_before == -1 ? 0 : brd_before+1); k < 9; k++) {
                    // cout << i << " "<< j << " "<< k << " " << rows[i][k]<< " "<< cols[j][k] << " "<< boxes[(i/3)*3 + j/3][k] << endl;

                    if(rows[i][k] == 0 && cols[j][k] == 0 && boxes[(i/3)*3 + j/3][k] == 0) {
                        brd[i][j] = k;

                        rows[i][k]++;
                        cols[j][k]++;
                        boxes[(i/3)*3 + j/3][k]++;

                        // cout << i << ", " << j << " " << char(brd[i][j]+'1') << endl;

                        break;
                    }
                }
                // We couldn't put any number in that position, so backtrack
                if(brd[i][j] == brd_before) {
                    brd[i][j] = -1;
                    if(brd_before!=-1) {
                        rows[i][brd_before]--;
                        cols[j][brd_before]--;
                        boxes[(i/3)*3 + j/3][brd_before]--;
                    }
                    // for(int l = 0; l<9; l++) {
                    //     cout << brd[i][l]+1 << " ";
                    // } cout << endl;
                    do {
                        j--;
                        if(j<0) {
                            j= 8;
                            i--;
                        } 
                    } while(i>=0 && board[i][j] != '.');

                    if(j==-1 || i==-1) {
                        cout << "that is not good:" << j << endl;
                    }

                    // cout << "Backtracked to " << i << ", " << j << endl;
                    j--;
                } else { // We have put a new number into the cell
                    if(brd_before != -1) {
                        rows[i][brd_before]--;
                        cols[j][brd_before]--;
                        boxes[(i/3)*3 + j/3][brd_before]--;
                    }
                }
            }
        }

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j]=='.')
                    board[i][j] = '1' + brd[i][j];
            }
        }
    }
};
