// Findig kth grammar word using Binary Tree
// SlothyCoder16
// August 18, 2020

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1)
            return 0;
        int number_of_nodes = pow(2,n-1);
        int mid_index = number_of_nodes / 2;
        if(k <= mid_index){
            return kthGrammar(n-1,k);
        }
        else{
            return !kthGrammar(n-1,k-mid_index);
        }
    }
};
