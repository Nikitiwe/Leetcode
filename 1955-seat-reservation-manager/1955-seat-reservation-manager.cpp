class SeatManager {
private:
    priority_queue<int> m;
public:
    SeatManager(int n) {
        for (int i=-1; i>=-n; i--) m.push(i);
    }
    
    int reserve() {
        int t=-m.top();
        m.pop();
        return t;
    }
    
    void unreserve(int seatNumber) {
        m.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */