// Number of ways square number is equal to product
// SlothyCoder16
// September 15, 2020

using lli = long long int;

class Solution {
public:
    int mod = 1e9+7;
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<unsigned long long, int> umap1;
        unordered_map<unsigned long long, int> umap2;

        for(int i=0; i<n1-1; i++) {
            for(int j=i+1; j<n1; j++) {
                long long product = (((lli)nums1[i]%mod)*((lli)nums1[j]%mod)%mod);
                umap1[product] += 1;
            }
        }
        for(int i=0; i<n2-1; i++) {
            for(int j=i+1; j<n2; j++) {
                unsigned long long product = (((lli)nums2[i]%mod)*((lli)nums2[j]%mod)%mod);
                umap2[product] += 1;
            }
        }

        int res=0;
        for(int i=0; i<n1; i++) {
            unsigned long long square = (((lli)nums1[i]%mod)*((lli)nums1[i]%mod)%mod);
            res+=umap2[square];
        }

        for(int i=0; i<n2; i++) {
            unsigned long long square = (((lli)nums2[i]%mod)*((lli)nums2[i]%mod)%mod);
            res += umap1[square];
        }

        return res;
    }
};
