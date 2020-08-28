// Pancake sorting using flip
// SlothyCoder16
// August 29, 2020

class Solution {
public:
    bool isSorted(vector<int> &a) {
        for(int i=0; i<a.size()-1; i++) {
            if(a[i] > a[i+1]) return false;
        }

        return true;
    }

    void reverseArray(vector<int> &A, int k) {
        vector<int> temp = A;
        A.clear();
        int i = k+1;
        while(k>=0) {
            A.push_back(temp[k]);
            k--;
        }

        while(i<temp.size()) {
            A.push_back(temp[i]);
            i++;
        }

    }

    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;

        int n = A.size();
        while(!isSorted(A)) {
            int k=0;
            for(int i=0; i<n; i++) {
                if(A[k] < A[i]) {
                    k = i;
                }
            }
            if(k == 0) {
                res.push_back(n);
                reverseArray(A, n - 1);
            } else {
                res.push_back(k+1);
                reverseArray(A, k);
                res.push_back(n);
                reverseArray(A, n - 1);
            }
            n--;

        }

        return res;
    }
};
