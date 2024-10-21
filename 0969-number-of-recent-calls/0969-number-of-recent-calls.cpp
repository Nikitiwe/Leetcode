class RecentCounter {
private:
    vector<int> arr;
public:
    RecentCounter() {
        arr.clear();
    }
    
    int ping(int t) {
        arr.push_back(t);
        int ans=1, r=arr.size()-2, k=arr[arr.size()-1]-3000;
        while (r>=0)
        {
            if (arr[r]>=k) ans++;
            else break;
            r--;
        }
        return ans;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */