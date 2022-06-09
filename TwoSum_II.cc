/* 
    167. Two Sum II - Input Array Is Sorted
    Recursive: O(2^n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() == 0) return result;
        if (numbers[f_index] + numbers[b_index] == target) {
            result.push_back(f_index+1);
            result.push_back(b_index+1);
            return result;
        }
        else {
            if(f_index >= numbers.size()-2) return result;
            if(b_index >= numbers.size()-1) {
                while(numbers[f_index] == numbers[f_index+1] && f_index+1 < numbers.size()-2) f_index++;
                f_index++;
                b_index = f_index+1;
            }
            else { 
                while(numbers[b_index] == numbers[b_index+1] && b_index+1 < numbers.size()-1) b_index++;
                b_index++;
            }
            twoSum(numbers, target);
        }
        return result;
    }
private:
    vector<int> result = {};
    int f_index = 0;
    int b_index = 1;
};

int main() {
    Solution s;
    vector<int> numbers = {1, 3, 4, 4};
    int target = 8;
    vector<int> output = s.twoSum(numbers, target);
    for(auto a : output) {
        cout << a << " " <<endl;
    }
} // need refactoring cause the performance is significantly not good...
