/* 
    88. Merge Sorted Array

    #1. minimize the size of array given
    #2. merge
    #3. sort
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int it = 0;
        for(int i = 0; i < n;) {
            if(it == n) {
                nums1.erase(nums1.begin()+it-1, nums1.end());
                nums1.insert(nums1.end(), nums2.begin()+i, nums2.begin()+n);
                cout << "break print vector" << endl;
                printVector(nums1);
                break;
            }
            cout << "for print vector" << endl;
            printVector(nums1);
            if(nums1.at(it) >= nums2[i]) {
                nums1.pop_back();
                nums1.insert(nums1.begin()+it, nums2[i]);
                i++;
                cout << "if print vector" << endl;
                printVector(nums1);
            }
            else it++;
        }
    }
    void printVector(vector<int> nums1) {
        for (auto& r : nums1) {
            cout << r << endl;
        }
        cout << "=============" << endl;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {4, 0, 0, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3, 5, 6};

    int m = 0;
    int n = 1;

    s.merge(nums1, m, nums2, n);
    for (auto& r : nums1) {
        cout << r << endl;
    }
}
