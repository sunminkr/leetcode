#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for(int i=0, j=1; j<nums.size(); j++) {    //O(n)
            if (nums.at(i) + nums.at(j)== target) {
                std::cout << i << " " << j << std::endl;
                nums.resize(0); //not sure if it has memory problem, theoretically OK with down-sizing (no change of actual stored area)
                nums.push_back(i);
                nums.push_back(j);
                //reassign values input vector > output vector
            }
            if (j==nums.size()-1) i++, j=i;              
            if (i==nums.size()-1) break;
        }
        return nums;
    }
    std::vector<int> nums;
    int target;
};

int main() {
    Solution solution;
    int n = 10000;  //vector size limit
    solution.nums.reserve(n);
    int cnt = 0;
    char str[n] = {};
    fgets(str, n, stdin);
    for(auto& i : str) {
        if (i >= '0' && i <= '9') {
            solution.nums.push_back(i - '0'); //store console input to vector
            cnt++;
        }
        if (i == ']') { 
            solution.nums.resize(cnt); //resize the vector
            if (cnt < 2) return 0; //vector size limit - just abort
            break;
        }
    }
    std::cin >> solution.target;
    solution.twoSum(solution.nums, solution.target);
    
    //output
    std::cout << "[" << solution.nums.at(0) << ", " << solution.nums.at(1) << "]" << std::endl;
    return 0;
}
