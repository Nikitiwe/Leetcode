class MyCalendar {
private:
    vector<vector<int>> arr;
public:
    MyCalendar() {
        arr.clear();        
    }
    
    bool book(int s, int e) {
        for (int i=0; i!=arr.size(); i++)
        {
            if (s<arr[i][1]&&arr[i][0]<e) return 0;
        }
        arr.push_back({s, e});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */