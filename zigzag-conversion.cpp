class Solution {
public:
    string convert(string s, int numRows) {
        // // Number of letters to make up one "zig" (down and diagonal up)
        // int oneZig = max(numRows + numRows-2, 1);
        // // Number of columns one "zig" is
        // int oneZigCols = max(1, (1 + numRows - 2));
        // // Number of columns
        // int numColumns = ceil(s.length() / (double)oneZig * oneZigCols);
        // // Container for output
        // char output[numRows][numColumns];
        // for (int i = 0; i < numRows; i++) {
        //     for (int j = 0; j < numColumns; j++) {
        //         output[i][j] = '\0';
        //     }
        // }


        // // For all zigs
        // int c = 0; // Character index
        // for (int i = 0; i < ceil(s.length() / (double)oneZig); i++) {
        //     // Make down line in zig
        //     for (int j = 0; j < numRows; j++) {
        //         if (c >= s.length())
        //             goto done;
        //         output[j][i * oneZigCols] = s[c];
        //         // cout << j << ", " << i * oneZigCols << endl;
        //         c++;
        //     }
        //     // Make diagonal up line in zig
        //     for (int j = 1; j < numRows - 1; j++) {
        //         if (c >= s.length())
        //             goto done;
        //         output[numRows - j - 1][i * oneZigCols + j] = s[c];
        //         // cout << numRows - j - 1 << ", " << i * oneZigCols + j<<  endl;
        //         c++;
        //     }
        // }
        // done:
        // string result;
        // for (int i = 0; i < numRows; i++) {
        //     for (int j = 0; j < numColumns; j++) {
        //         if (output[i][j]) {
        //             result.push_back(output[i][j]);
        //         }
        //     }
        // }

        string result;
        // Number of letters to make up one "zig" (down and diagonal up)
        int oneZig = max(numRows + numRows-2, 1);
        // Number of columns one "zig" is
        int oneZigCols = max(1, (1 + numRows - 2));
        // Iterate over all the rows in the pattern
        for (int row = 0; row < numRows; row++) {
            int x = (numRows - 1 - row) * 2;
            // j is a counter for number of chars in that row
            // i is the index of the current char to be appended
            for (int i = row, j = 0; i < s.length(); j++) {
                result.push_back(s[i]);
                int y = (j % 2 == 0 ? x : oneZig - x);
                if(y == 0)
                    y = oneZig;
                i += y;
            }
        }
        
        return result;
    }
};
