/*
 * 216. Combination Sum III
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subtarget;
        subtarget.reserve(k);
        for (int r=0; r<k; r++) subtarget.push_back(r+1); // initialise sub vector, O(k)
        if(vector_sum(subtarget)>n) return target; // if n is smaller than a min_sum, there won't be any possible result
        
        int temp_n = n - (vector_sum(subtarget) - subtarget.size());
        if (temp_n > 9) temp_n = 9; //Only numbers 1 though 9 are used
        base.reserve(temp_n);
        for (int p=0; p<temp_n; p++) base[p] = p+1; // initialise base vector, O(k)

        subtarget.resize(0);
        combination(subtarget, temp_n, k, n, 0, 0);    // because k is variable, use recursive.
        return target;
    }

    int vector_sum(vector<int> subtarget) {
        int sum = 0;
        for (int i=0; i<subtarget.size(); i++) sum+=subtarget[i];
        return sum;
    }

    void combination(vector<int> subtarget, int n, int k, int result, int index, int count) {
        if(k==1) {
            for(int i=0; i<n; i++) {
                subtarget.push_back(base[index+i]);
                if(vector_sum(subtarget) == result) { target.push_back(subtarget); return; }    //target found
                subtarget.pop_back();
            }
            subtarget.clear();
            subtarget.resize(0);
            return;
        }
        else if (k==n) {
            for(int i=0; i<n; i++) subtarget.push_back(base[index+i]);
            if(vector_sum(subtarget) == result) { target.push_back(subtarget); return; }    //target found
            subtarget.clear();
            subtarget.resize(0);
            return;
        }
        combination(subtarget, n-1, k, result, index+1, count);

        subtarget.push_back(base[index]);
        count++;
        combination(subtarget, n-1, k-1, result, index+1, count);
    }

private:
    vector<vector<int>> target;
    vector<int> base;
};

int main() {
    int k = 4, n = 1; // Testcase: 2 <= k <= 9, 1 <= n <= 60
    Solution s;
    vector<vector<int>> result = s.combinationSum3(k, n);
    //cout << "Function call" << endl;
    if (result.size() == 0) cout << "[]" << endl;
    for(int i=0; i < result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
} //must do refactoring..
