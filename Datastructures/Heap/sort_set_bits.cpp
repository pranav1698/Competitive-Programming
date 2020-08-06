// Sort the numbers by the number of set bits in the number
// SlothyCoder16
// August 06, 2020

class compare {
public:
    bool operator()(const pair<int, int> p1, const pair<int, int> p2) {
        if(p1.second ==p2.second) return p1.first > p2.first;
        return p1.second > p2.second;
    }
};

class Solution {
public:
    int numberSetBits(int x) {
        int count=0;
        while(x!=0) {
            count++;
            x = x & (x-1);
        }

        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for(int i=0; i<arr.size(); i++)
            pq.push({arr[i], numberSetBits(arr[i])});

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
