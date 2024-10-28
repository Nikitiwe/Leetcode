class StockSpanner {
private:
    vector<int> arr;
public:
    StockSpanner() {
        arr.clear();
    }
    
    int next(int p) {
        arr.push_back(p);
        int l=arr.size()-1;
        while (l>=0&&arr[l]<=arr[arr.size()-1]) l--;
        return arr.size()-1-l;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */