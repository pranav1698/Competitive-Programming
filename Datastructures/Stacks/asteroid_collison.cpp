// Implementation of Asteroid Collison using stack
// SlothyCoder16
// July 18, 2020

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> s;
        for(int i=0; i<asteroids.size(); i++){
            if(asteroids[i] >= 0){
                s.push(asteroids[i]);
            } else {
                s = getStack(s, asteroids[i]);
            }
        }

        vector<int> finalRes;
        while(!s.empty()) {
            int n = s.top();
            finalRes.push_back(n);
            s.pop();
        }

        for(int i=finalRes.size() - 1; i>=0; i--) {
            res.push_back(finalRes[i]);
        }

        return res;
    }

    stack<int> getStack(stack<int> &s, int num) {
        int prev = INT_MIN;
        if(!s.empty()) {
            prev = s.top();
            s.pop();
        }

        if(prev < 0) {
            if(prev != INT_MIN)
                s.push(prev);
            s.push(num);
        } else {
            int size1 = abs(prev);
            int size2 = abs(num);
            if(size1 > size2){
                s.push(prev);
            } else if(size2 > size1) {
                stack<int> subRes = getStack(s, num);
                return subRes;
            }
        }

        return s;
    }
};
