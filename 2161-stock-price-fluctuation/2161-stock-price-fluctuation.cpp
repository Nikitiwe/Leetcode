class StockPrice {
public:
    priority_queue<pair<int, int>> q; // время + значение
    priority_queue<pair<int, int>> ma, mi; // значение + время
    unordered_map<int, int> m;
    StockPrice() {
        return;
    }
    
    void update(int timestamp, int price) {
        m[timestamp] = price;
        q.push({timestamp, price});
        ma.push({price, timestamp});
        mi.push({-price, timestamp});
    }
    
    int current() {
        while (q.size() > 0)
        {
            if (m[q.top().first] == q.top().second) break;
            else q.pop();
        }
        return q.top().second;
    }
    
    int maximum() {
        while (ma.size() > 0)
        {
            if (m[ma.top().second] == ma.top().first) break;
            else ma.pop();
        }
        return ma.top().first;
    }
    
    int minimum() {
        while (mi.size() > 0)
        {
            if (m[mi.top().second] == - mi.top().first) break;
            else mi.pop();
        }
        return - mi.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */