class MyHashMap {
public:
    vector<int> arr;
    MyHashMap() {
        vector<int> tarr(100007, -1);
        arr = tarr;
    }
    
    void put(int key, int value) {
        arr[key%100007] = value;
    }
    
    int get(int key) {
        return arr[key%100007];
    }
    
    void remove(int key) {
        arr[key%100007] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */