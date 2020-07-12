// Valid Balanced String for given input
// SlothyCoder16
// July 13, 2020

class Solution {
public:
    char pop(char* stack, int* numElements) {
        char res = stack[*numElements - 1];
        stack[*numElements - 1] = '\0';
        *numElements = *numElements - 1;
        return res;
    }


    int push(char* stack, int numElements, char val) {
        stack[numElements] = val;
        numElements = numElements + 1;
        return numElements;
    }

    bool isValid(string s) {
        int numElements = 0;
        char stack[1000000];



        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(' || s[i] == '['  || s[i] == '{') {
                numElements = push(stack, numElements, s[i]);
            } else {
                if(numElements == 0)
                    return false;

                char popResult = pop(stack, &numElements);
                if(popResult == '(' && s[i] != ')') {
                    return false;
                }
                if(popResult == '[' && s[i] != ']') {
                    return false;
                }
                if(popResult == '{' && s[i] != '}') {
                    return false;
                }
            }
        }

        return (numElements == 0);
    }
};
