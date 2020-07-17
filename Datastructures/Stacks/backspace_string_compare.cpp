// Comparing Strings with Backspace
// SlothyCoder16
// July 17, 2020

class StringStack{
public:
    int numElements;
    char stack[1000000];

    StringStack() {
        this->numElements = 0;
    }

    void push(char x) {
        this->stack[this->numElements] = x;
        this->numElements = this->numElements + 1;
    }

    void pop() {
        if(numElements == 0)
            return;
        this->stack[(this->numElements) - 1] = '\0';
        this->numElements = this->numElements - 1;
    }

    string finalString() {
        string s="";

        for(int i=0; i<this->numElements; i++)
            s = s + this->stack[i];

        return s;
    }
};

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        StringStack* obj1 = new StringStack();
        StringStack* obj2 = new StringStack();

        for(int i=0; i<S.length(); i++) {
            if(S[i] == '#') {
                obj1->pop();
            } else {
                obj1->push(S[i]);
            }
        }

        for(int i=0; i<T.length(); i++) {
            if(T[i] == '#') {
                obj2->pop();
            } else {
                obj2->push(T[i]);
            }
        }

        string s1 = obj1->finalString();
        string s2 = obj2->finalString();

        cout << s1 << " " << s2 << endl;
        if(s1 == s2)
            return true;

        return false;

    }
};
