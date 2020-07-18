// Flatten Nested List Iteration using stack and recursion
// SlothyCoder16
// July 18, 2020

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
    stack<int> s;

    NestedIterator(vector<NestedInteger> &nestedList) {
        vector<int> finalRes = getFinalRes(nestedList);
        for(int i=finalRes.size()-1; i>=0; i--){
            this->s.push(finalRes[i]);
        }
    }

    vector<int> getFinalRes(vector<NestedInteger> &nestedList) {
        vector<int> res;

        for(int i=0; i<nestedList.size(); i++) {
            if(nestedList[i].isInteger()) {
                res.push_back(nestedList[i].getInteger());
            } else {
                vector<int> subRes = getFinalRes(nestedList[i].getList());
                for(int i=0; i<subRes.size(); i++)
                    res.push_back(subRes[i]);
            }
        }

        return res;
    }

    int next() {
        int res = this->s.top();
        this->s.pop();
        return res;
    }

    bool hasNext() {
        if(!(this->s).empty()){
            return true;
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
