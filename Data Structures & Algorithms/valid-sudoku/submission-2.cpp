#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool squares[9][9] = {};

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                
                if(board[i][j] == '.'){
                    continue;
                }

                int index = (i / 3) * 3 + (j / 3);
                int digit = board[i][j] - '1';
                
                if(rows[i][digit] || cols[j][digit] || squares[index][digit]){
                    return false;
                }

                rows[i][digit] = 1;
                cols[j][digit] = 1;
                squares[index][digit] = 1;
            }
        }

        return true;
    }
};
