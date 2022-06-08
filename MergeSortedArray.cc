/* 
    88. Merge Sorted Array
    O(2N)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int itr=0;
        for (int i=0; i<n;) {
            if(nums1[itr] == 0) {
                nums1.erase(nums1.begin()+itr, nums1.end());
                nums1.insert(nums1.end(), nums2.begin()+i, nums2.begin()+n);
                break;
            }
            else {
                if(nums1[itr] >= nums2[i]) {
                    nums1.pop_back();
                    nums1.insert(nums1.begin()+itr, nums2[i]);
                    i++;
                }
                itr++;
            }
        }
    }
    void printVector(vector<int> nums1) {
        for (auto& r : nums1) {
            cout << r << endl;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {4, 0, 0, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3, 5, 6};

    int m = 1;
    int n = 5;

    s.merge(nums1, m, nums2, n);
    s.printVector(nums1);
}
