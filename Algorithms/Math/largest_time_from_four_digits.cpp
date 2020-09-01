// Largest time formed using 4 digits
// SlothyCoder16
// September 01, 2020

class Solution {
public:
    int binarySearch(vector<int> &A, int x) {
        int start = 0;
        int end = A.size() -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(A[mid] > x) {
                end = mid - 1;
            } else if(A[mid] < x) {
                start = start + 1;
            } else {
                A[mid] = -1;
                return mid;
            }
        }

        return -1;
    }

    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        string res = "";

        int i;
        vector<int> temp=A;
        if(binarySearch(temp,2) != -1) {
            res = res + '2';
            sort(temp.begin(), temp.end());
            for(i=3;i>=0;i--){
                if(binarySearch(temp, i) != -1) {
                    res = res + to_string(i);
                    break;
                }
            }
            if(i != -1) {
                res = res + ':';
                sort(temp.begin(), temp.end());
                for(i=5;i>=0;i--){
                    if(binarySearch(temp, i) != -1) {
                        res = res + to_string(i);
                        break;
                    }
                }
                if(i != -1) {
                    for(int i=0; i<4; i++) {
                        if(temp[i] != -1) {
                            res = res + to_string(temp[i]);
                        }
                    }
                    return res;
                }
            }
        }

        temp=A;
        res="";
        if(binarySearch(temp, 1) != -1) {
            res = res + '1';
            sort(temp.begin(), temp.end(), greater<int>());
            res=res + to_string(temp[0]);
            temp[0] = -1;
            res = res + ':';
            sort(temp.begin(), temp.end());
            for(i=5;i>=0;i--){
                if(binarySearch(temp, i) != -1) {
                    res = res + to_string(i);
                    break;
                }
            }
            if(i != -1) {
                for(int i=0; i<4; i++) {
                    if(temp[i] != -1) {
                        res = res + to_string(temp[i]);
                    }
                }
                return res;
            }
        }

        temp=A;
        res="";
        if(binarySearch(temp, 0) != -1) {
            res = res + '0';
            sort(temp.begin(), temp.end(), greater<int>());
            res = res + to_string(temp[0]);
            res = res + ':';
            temp[0] = -1;
            sort(temp.begin(), temp.end());
            for(i=5;i>=0;i--){
                if(binarySearch(temp, i) != -1) {
                    res = res + to_string(i);
                    break;
                }
            }
            if(i != -1) {
                for(int i=0; i<4; i++) {
                    if(temp[i] != -1) {
                        res = res + to_string(temp[i]);
                    }
                }
                return res;
            }
        }

        res="";
        return res;
    }
};
