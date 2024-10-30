class MyCalendarTwo {
private:
    vector<vector<int>> arr, arr2;
public:
    MyCalendarTwo() {
        arr.clear();
        arr2.clear();
    }
    
    bool book(int s, int e) {
        bool isit=1;
        for (int i=0; i!=arr2.size(); i++)
        {
            if (s<arr2[i][1]&&e>arr2[i][0])
            {
                isit=0;
                break;
            }
        }
        if (isit==1)
        {
            for (int i=0; i!=arr.size(); i++)
            {
                if (s<arr[i][1]&&e>arr[i][0])
                {
                    arr2.push_back({max(s, arr[i][0]), min(e, arr[i][1])});
                }
            }
            arr.push_back({s, e});
            return 1;
        }
        else return 0;        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */