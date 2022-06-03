/*
    304. Range Sum Query 2D - Immutable
    Dynamic Programming
 */

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        dp = matrix;
        //calculate all sums and make dp table
        for(int i=0; i<dp.size();i++) {
            if(i == 0) {
                for(int j=1; j<dp[i].size(); j++) {
                    dp[i][j] = dp[i][j-1] + dp[i][j];
                }
            }
            else {
                dp[i][0] = dp[i-1][0] + dp[i][0]; 
                for(int j=1; j<dp[i].size(); j++) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j] + dp[i][j] - dp[i-1][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = dp[row2][col2];
        if(row1 != 0) {
            result -= dp[row1-1][col2];
        }
        if(col1 != 0) {
            result -= dp[row2][col1-1];
        }
        if(row1 != 0 && col1 != 0) { 
            result += dp[row1-1][col1-1];
        }
        cout << result << endl;
        return result;
    }

    void printMatrix(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        } //let's change this to range-based for loop 
    }
};

int main () {
    
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                  {5, 6, 3, 2, 1}, 
                                  {1, 2, 0, 1, 5}, 
                                  {4, 1, 0, 1, 7}, 
                                  {1, 0, 3, 0, 5}};
    NumMatrix* obj = new NumMatrix(matrix);
 
    int param_1 = obj->sumRegion(2,1,4,3);
    int param_2 = obj->sumRegion(1,1,2,2);
    int param_3 = obj->sumRegion(1,2,2,4);

    /*
    vector<vector<int>> matrix = {{-4,-5}};
    NumMatrix* obj = new NumMatrix(matrix);
 
    int param_1 = obj->sumRegion(0,0,0,0);
    int param_2 = obj->sumRegion(0,0,0,1);
    int param_3 = obj->sumRegion(0,1,0,1);
    */
}
