/*
 * 17.Letter Combinations of a phone number
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> TargetSet;
    vector<string> BaseSet = {"abc" 
                            , "def"
                            , "ghi"
                            , "jkl"
                            , "mno"
                            , "pqrs"
                            , "tuv"
                            , "wxyz"};
public:
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return result;
        /* limit the size of vector. optimized? or no difference? : 1MB better
        int r_size = 1;
        for(int i=0; i< digits.size(); i++) {
            if(digits[i] == '7' || digits[i] == '9') r_size*=4;
            else r_size*=3;
        }
        result.reserve(r_size);
        */
        //using recursive function
        for(int i=0; i<digits.size(); i++) {
            int length = (int)digits.at(i) - '0' -2;
            TargetSet.push_back(BaseSet[length]);
        }
        string subvector = "";
        int *index = new int[digits.size()]();
        matchCombination(subvector, index, 0, digits.size()-1);
        delete[] index;
        return result;
    }
    void matchCombination(string subvector, int* index, int count, int endpoint) {
        if(index[count] == TargetSet[count].size()) {
            subvector.pop_back();
            index[count] = 0;
            count-=2;
        } else {
            subvector.append(sizeof(char), TargetSet[count].at(index[count]));
            index[count]++;
        }
        if(count == endpoint) { 
            result.push_back(subvector); 
            subvector.pop_back(); 
            count--; 
        }
        if(count==-2) return;
        matchCombination(subvector, index, count+1, endpoint);
    }
    void printVector(vector<string> vec) {
        for(int i=0; i<vec.size(); i++) cout << vec[i] << " ";
        cout << endl;
    }
};

int main () {
    string digits = "5678";
    Solution s;
    s.letterCombinations(digits);
    cout << "result: ";
    s.printVector(s.result); 
    return 0;
}//need refactoring
