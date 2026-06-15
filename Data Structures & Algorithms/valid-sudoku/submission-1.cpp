#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, set<char>> rows(n);
        unordered_map<int, set<char>> cols(n);
        unordered_map<int, set<char>> squares(n);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                
                if(board[i][j] == '.'){
                    continue;
                }

                int index = (i / 3) * 3 + (j / 3);
                auto find_row = rows[i].find(board[i][j]);
                auto find_col = cols[j].find(board[i][j]);
                auto find_sq = squares[index].find(board[i][j]);

                if(find_row != rows[i].end() || find_col != cols[j].end() || find_sq != squares[index].end()){
                    return false;
                }
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                squares[index].insert(board[i][j]);
            }
        }

        return true;
    }
};
