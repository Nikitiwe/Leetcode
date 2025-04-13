class MyCalendarThree {
public:
    map<int, int> m;
    MyCalendarThree() {
        return;
    }
    
    int book(int x, int y) {
        int ma = 0, t = 0;
        m[x]++;
        m[y]--;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            t += i->second;
            ma = max(ma, t);
        }
        return ma;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */