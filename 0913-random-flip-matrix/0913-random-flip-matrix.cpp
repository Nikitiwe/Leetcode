class Solution {
public:
    unordered_set<int> arr;
    int x, y;

    Solution(int m, int n) {
        x = m;
        y = n;
    }
    
    vector<int> flip() {
        int t = rand() % (x*y);
        while (arr.count(t) == 1) t = rand() % (x*y);
        arr.insert(t);
        return {t%x, t/x};
    }
    
    void reset() {
        arr.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */