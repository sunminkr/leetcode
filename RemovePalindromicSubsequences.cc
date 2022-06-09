/* 
    1332. Remove Palindromic Subsequences
    O(n)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s == "") return 0;
        else if(isPalindrome(s)) return 1;
        else return 2;
    }
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size()-1;

        for (int i=0; i<(s.size()/2)+1; i++) {
            if(s.at(front) == s.at(back)) {
                front++;
                back--;
            }
            else return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    string input = "babab";
    cout << s.removePalindromeSub(input) << endl;
}
