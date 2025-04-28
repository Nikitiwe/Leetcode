class DataStream {
public:
    int count, val, k;
    DataStream(int value, int kk) {
        count = 0;
        val = value;
        k = kk;
    }
    
    bool consec(int num) {
        if (num == val) count++;
        else count = 0;
        if (count >= k) return 1;
        else return 0;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */