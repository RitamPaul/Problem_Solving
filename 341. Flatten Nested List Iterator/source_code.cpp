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
    vector<int> arr;
    int ind;
    void helper(vector<NestedInteger> &list){
        for(auto &v : list){
            if(v.isInteger()){
                arr.push_back(v.getInteger());
                ++ind;
            }
            else{
                helper(v.getList());
                ++ind;
            }
        }
    }
    NestedIterator(vector<NestedInteger> &list) {
        ind = 0;
        for(auto &v : list){
            if(v.isInteger()){
                arr.push_back(v.getInteger());
                ++ind;
            }
            else{
                helper(v.getList());
            }
        }
        ind = -1;
    }
    
    int next() {
        ++ind;
        return arr[ind];
    }
    
    bool hasNext() {
        return ind + 1 < arr.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */