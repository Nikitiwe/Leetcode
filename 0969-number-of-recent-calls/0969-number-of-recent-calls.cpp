class RecentCounter {
private:
    vector<int> arr;
    int c=0;
public:
    RecentCounter() {
        arr.clear();
        c=0;
    }
    
    int ping(int t) {
        arr.push_back(t);
        int r=c, k=arr[arr.size()-1]-3000;
        while (r<arr.size())
        {
            if (arr[r]>=k)
            {
                c=r;
                return arr.size()-c;
            }
            r++;
        }
        return -1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */