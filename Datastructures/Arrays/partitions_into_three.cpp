// Partititoning the array into three subarrays of equal sum
// SlothyCoder16
// September 21, 2020

// O(A^2) approach
int Solution::solve(int A, vector<int> &B) {
    vector<int> prefix(A, 0);
    vector<int> suffix(A, 0);
    int totalSum=0;
    for(int i=0; i<A; i++) totalSum+=B[i];
    if((totalSum%3)!=0) return 0;

    prefix[0]=B[0];
    for(int i=1; i<A; i++) prefix[i]=prefix[i-1]+B[i];
    suffix[A-1]=B[A-1];
    for(int i=A-2; i>=0; i--) suffix[i]=suffix[i+1]+B[i];

    int count=0;
    for(int i=0; i<A; i++) {
        if(prefix[i] == totalSum/3) {
            for(int j=i+2; j<A; j++) {
                if(suffix[j] == totalSum/3) count++;
            }
        }
    }

    return count;
}


// O(AlogA) approach
int binarySearch(vector<int> &arr, int x) {
    int start=0;
    int end=arr.size()-1;

    while(start<=end) {
        int mid= start + (end-start)/2;

        if(arr[mid] <= x) {
            start=mid+1;
        } else if(arr[mid]>x && arr[mid-1] <= x) {
            return mid;
        } else if(arr[mid]>x && mid==0) {
            return mid;
        } else {
            end = mid-1;
        }
    }

    return -1;
}


int Solution::solve(int A, vector<int> &B) {
    vector<int> prefix(A, 0);
    vector<int> suffix(A, 0);
    int totalSum=0;
    for(int i=0; i<A; i++) totalSum+=B[i];
    if((totalSum%3)!=0) return 0;

    prefix[0]=B[0];
    for(int i=1; i<A; i++) prefix[i]=prefix[i-1]+B[i];
    suffix[A-1]=B[A-1];
    for(int i=A-2; i>=0; i--) suffix[i]=suffix[i+1]+B[i];

    vector<int> v;
    for(int i=0; i<A; i++) if(suffix[i] == totalSum/3) v.push_back(i);

    int count=0;
    for(int i=0; i<A; i++) {
        if(prefix[i] == totalSum/3) {
            int res = binarySearch(v, i+1);
            if(res != -1) count += v.size()-res;
        }

    }

    return count;
}
