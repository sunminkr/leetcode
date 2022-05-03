/*
905. Sort Array By Parity
*/
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums) {
        for (int i=1, j=0; i<nums.size(); i++) {
            if(nums.at(j) % 2 == 0) j++, i=j;
            if(nums.at(i) % 2 == 0) {
                std::swap(nums[i], nums[j]);    //swap
            }
        }
        return nums;
    }
    std::vector<int> nums;
};

int main() {
    Solution solution;
    solution.nums = {10, 1, 3, 9, 16, 40, 22, 33};   //testcase
    solution.twoSum(solution.nums);
    for(auto& i : solution.nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
