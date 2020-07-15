// Get Decimal value from bit array
// SlothyCoder16
// July 16, 2020


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> number;

        while(head != NULL) {
            number.push_back(head->val);
            head = head->next;
        }

        unsigned long long int sum = 0;
        for(int i=0; i<number.size(); i++) {
            sum += (1 << i) * number[number.size() - (i + 1)];
        }


        return sum;
    }
};
