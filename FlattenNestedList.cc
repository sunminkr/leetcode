// 341. Flatten Nested List Iterator

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        NestedRecursiveSol(nestedList); //multi-nested list > use recursive function call
    }
    
    int next() {
        return nums[index++];
    }
    
    bool hasNext() {
        if(index < nums.size()) return 1;
        return 0;
    }
private:
    int index = 0;
    vector<int> nums;
    void NestedRecursiveSol(vector<NestedInteger> &nestedList) {
        for(auto& j : nestedList) {
            if(j.isInteger()) nums.push_back(j.getInteger());
            else NestedRecursiveSol(j.getList());
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
