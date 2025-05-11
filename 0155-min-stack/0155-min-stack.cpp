class MinStack {
public:
    map<int, int> m;
    vector<int> arr;
    MinStack() {
        return;
    }
    
    void push(int val) {
        arr.push_back(val);
        m[val]++;
    }
    
    void pop() {
        m[arr.back()]--;
        if (m[arr.back()] == 0) m.erase(arr.back());
        arr.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return m.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */