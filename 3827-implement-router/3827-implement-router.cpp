class Router {
public:
    deque<tuple<int, int, int>> q;
    int n = 0;
    unordered_map<int, vector<int>> m;
    unordered_map<int, int> startid;
    set<string> s;
    Router(int memoryLimit) {
        n = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string t = to_string(source) + ',' + to_string(destination) + ',' + to_string(timestamp);
        if (s.count(t) == 0)
        {
            m[destination].push_back(timestamp);
            s.insert(t);
            q.push_back({source, destination, timestamp});
            if (q.size() > n)
            {
                auto [source, destination, timestamp] = q.front();
                q.pop_front();
                startid[destination]++;
                string t = to_string(source) + ',' + to_string(destination) + ',' + to_string(timestamp);
                s.erase(t);
            }
            return true;
        }
        else return false;
    }
    
    vector<int> forwardPacket() {
        if (q.size() == 0) return {};
        auto [source, destination, timestamp] = q.front();
        q.pop_front();
        startid[destination]++;
        string t = to_string(source) + ',' + to_string(destination) + ',' + to_string(timestamp);
        s.erase(t);
        return {source, destination, timestamp};
    }
    
    int getCount(int dest, int startTime, int endTime) {

        int l = startid[dest], r = m[dest].size() - 1, med, mi = m[dest].size();
        while (l <= r)
        {
            med = (l+r)/2;
            if (m[dest][med] < startTime) l = med+1;
            else
            {
                mi = min(mi, med);
                r = med-1;
            }
        }
            int ma = -1;
            l = startid[dest], r = m[dest].size() - 1;
            while (l <= r)
            {
                med = (l+r)/2;
                if (m[dest][med] > endTime) r = med-1;
                else
                {
                    ma = max(ma, med);
                    l = med+1;
                }
            }
        if (ma >= mi) return ma - mi + 1;
        return 0;        
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */