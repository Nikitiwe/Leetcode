class UndergroundSystem {
private:
    unordered_map<int, string> l;
    unordered_map<int, double> s;
    unordered_map<string, double> time, count;
public:
    UndergroundSystem() {
        l.clear();
        s.clear();
        time.clear();
        count.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        l[id]=stationName;
        s[id]=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        time[l[id]+"."+stationName]+=t-s[id];
        count[l[id]+"."+stationName]+=1.0;
        time.erase(l[id]);
        count.erase(l[id]);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return time[startStation+"."+endStation]/count[startStation+"."+endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */