// Implementation of mini parser question
// SlothyCoder16
// July 18, 2020


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger list(const string& str, int& i){
        i++;
        NestedInteger ret;
        if(str[i]==']'){
            i++;
            return ret;
        }
        ret.add(NestedInteger(f(str,i)));
        while(str[i]!=']'){
            i++;
            ret.add(NestedInteger(f(str,i)));
        }
        i++;
        return ret;
    }
    int number(const string& str, int& i){
        int ret = 0;
        if(str[i] == '-'){
            i++;
            return -number(str,i);
        }
        while(i<str.size()&&str[i]>='0'&&str[i]<='9'){
            ret = ret * 10 + str[i] - '0';
            i++;
        }
        return ret;
    }

    NestedInteger f(const string& str, int&i){
        if(str[i] == '['){
            return list(str,i);
        }
        return number(str,i);
    }

    NestedInteger deserialize(string s) {
        int i = 0;
        return f(s,i);
    }
};
