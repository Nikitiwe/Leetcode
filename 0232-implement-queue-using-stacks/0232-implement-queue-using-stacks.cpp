class MyQueue {
public:
    stack<int> f, s;
    MyQueue() {
        return;
    }
    
    void push(int x) {
        if (f.size() == 0)
        {
            while (s.size() > 0)
            {
                f.push(s.top());
                s.pop();
            }
            f.push(x);
            while (f.size() > 0)
            {
                s.push(f.top());
                f.pop();
            }
        }
        else
        {
            while (f.size() > 0)
            {
                s.push(f.top());
                f.pop();
            }
            s.push(x);
            while (s.size() > 0)
            {
                f.push(s.top());
                f.pop();
            }
        }
    }
    
    int pop() {
        int ans;
        if (s.size() > 0)
        {
            ans = s.top();
            s.pop();
        }
        else
        {
            ans = f.top();
            f.pop();
        }
        return ans;
    }
    
    int peek() {
        if (s.size() > 0)
        {
            int ans = s.top();
            return ans;
        }
        else
        {
            int ans = f.top();
            return ans;
        }
    }
    
    bool empty() {
        if (s.size() > 0 || f.size() > 0) return 0;
        else return 1;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */