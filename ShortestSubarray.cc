/*
  581. Shortest unsorted continuous subarray
*/

#include <iostream>
#include <vector>

class Solution { 
public: 
    int findUnsortedSubarray(std::vector<int>& nums) {
        int max = nums[0], min = nums[nums.size()-1];
        int l_index = nums.size()-1, r_index = 0;
        for(int i=0; i<nums.size(); i++) {  //find range - setting right index
            if(nums[i] < max) r_index=i;
            else max = nums[i];
        }
        if(r_index == 0) return 0;  //already in ascending order
        for(int j=nums.size()-1; j>=0; j--) {   //find range - setting left index
            if(nums[j] > min) l_index=j;
            else min = nums[j];
        }
        return r_index-l_index+1;
    }
};

int main() {
    Solution sol;
    std::vector<int> numbers = {1, 4, 3, 2, 2}; //test case
    int output = sol.findUnsortedSubarray(numbers);
    std::cout << output << std::endl;
    return 0;
}
