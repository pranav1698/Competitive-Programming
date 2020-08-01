// Designing your own Hash Set without using stl library
// SlothyCoder16
// August 03, 2020

class MyHashSet {
public:
    /** Initialize your data structure here. */
    bool arr[1000000]{false};

    MyHashSet() {

    }

    void add(int key) {
        this->arr[key] = true;
    }

    void remove(int key) {
        this->arr[key] = false;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return this->arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
