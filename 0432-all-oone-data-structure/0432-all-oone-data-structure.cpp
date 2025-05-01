class AllOne {
public:
    unordered_map<string, int> m;
    priority_queue<pair<int, string>> mi, ma;
    AllOne() {
        return;
    }
    
    void inc(string key) {
        m[key]++;
        ma.push({m[key], key});
        mi.push({ - m[key], key});
    }
    
    void dec(string key) {
        m[key]--;
        if (m[key] == 0) m.erase(key);
        else
        {
            ma.push({m[key], key});
            mi.push({ - m[key], key});
        }
    }
    
    string getMaxKey() {
        while (ma.size() > 0 && m[ma.top().second] != ma.top().first) ma.pop();
        if (ma.size() > 0) return ma.top().second;
        else return "";
    }
    
    string getMinKey() {
        while (mi.size() > 0 && m[mi.top().second] != - mi.top().first) mi.pop();
        if (mi.size() > 0) return mi.top().second;
        else return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */