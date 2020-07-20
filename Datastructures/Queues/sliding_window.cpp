// Implementation of Sliding Window problem using queue
// SlothyCoder16
// July 20, 2020

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int n) {
        queue<int> q;
        map<int, int> m;
        vector<int> res;

        for(int i=0; i<A.size(); i++) {
            m[A[i]] = i;
            q.push(A[i]);

            if(i > (n + m[q.front()] - 1)) {
                // cout << q.front() << " " << A[i] << endl;
                int index = m[q.front()];
                int maxElement = INT_MIN;
                q.pop();
                while(!q.empty()) {
                    q.pop();
                }
                for(int j=index + 1; j<=i; j++) {
                  maxElement = max(A[j], maxElement);
                }

                q.push(maxElement);

                for(int j=index + 1; j<=i; j++){
                  if(A[j] != q.front())
                    q.push(A[j]);
                }
            }

            if(A[i] > q.front()) {
                while(!q.empty()) {
                    q.pop();
                }

                q.push(A[i]);
            }


            if(i >= (n-1)) {
                res.push_back(q.front());
            }
        }
        return res;
    }
};
