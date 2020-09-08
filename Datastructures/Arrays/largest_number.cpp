// Making Largest Number from the array of numbers
// SlothyCoder16
// September 29, 2020

string Solution::largestNumber(const vector<int> &A) {
    vector<string> a;
    for(int i=0; i<A.size(); i++) a.push_back(to_string(A[i]));
    sort(a.begin(), a.end(), [](const string a, const string b){
        string xy = a+b;
        string yx = b+a;

        return xy>yx;
    });

    string res="";
    bool flag=false;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != "0") {
            res+=a[i];
            flag=true;
        }
    }

    return flag ? res: "0";
}
