// Finding super ugly using hash map and min heap
// SlothyCoder16
// August 03, 2020


typedef unsigned long long int ll;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        ll curr;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        unordered_map<ll, int> umap;
        umap[1]=1;
        pq.push(1);

        int i=0;
        while(i != n && !pq.empty()) {
            curr = pq.top();
            pq.pop();

            for(int j=0; j<primes.size(); j++) {
                if(umap[primes[j] * curr] == 0)
                    pq.push(primes[j] * curr);
                umap[primes[j] * curr] = umap[primes[j] * curr] + 1;
            }

            i++;
        }

        return curr;
    }
};
