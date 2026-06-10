#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix = vector<vector<int>>(rows +1, vector<int>(cols + 1, 0));

        for(int i = 1; i <= rows; ++i){
            for(int j = 1; j <= cols; ++j){
                prefix[i][j] = matrix[i - 1][j - 1];
                prefix[i][j] += prefix[i][j - 1];
                prefix[i][j] += prefix[i - 1][j];
                prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1;
        ++col1;
        ++row2;
        ++col2;
        
        int sum = prefix[row2][col2];
        sum -= prefix[row2][col1 - 1];
        sum -= prefix[row1 - 1][col2];
        sum += prefix[row1 - 1][col1 - 1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */