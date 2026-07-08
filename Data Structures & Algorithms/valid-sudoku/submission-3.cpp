#include <unordered_set>

using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<unordered_set<char>> square_map(9);
        vector<unordered_set<char>> row_map(9);
        vector<unordered_set<char>> col_map(9);

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                char num = board[i][j];

                if(num == '.'){
                    continue;
                }

                int square_index = (i / 3) * 3 + (j / 3);
                
                if(square_map[square_index].count(num) || row_map[i].count(num) 
                || col_map[j].count(num)){
                    return false;
                }

                square_map[square_index].insert(num);
                row_map[i].insert(num);
                col_map[j].insert(num);
            }
        }

        return true;
    }
};
