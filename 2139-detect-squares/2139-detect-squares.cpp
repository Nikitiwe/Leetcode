class DetectSquares {
public:
    unordered_map<int, int> m;
    DetectSquares() {}
    
    void add(vector<int> p) {
        m[p[0]*10000 + p[1]]++;
    }
    
    int count(vector<int> p) {
        int ans = 0;
        int x = p[0], y = p[1];
        int d = 1;
        while (x + d <= 1000 && y + d <= 1000)
        {
            if (m.count((x+d)*10000 + y+d) != 0 && m.count((x)*10000 + y+d) != 0 && m.count((x+d)*10000 + y) != 0)
            {
                ans += m[(x+d)*10000 + y+d] * m[(x)*10000 + y+d] * m[(x+d)*10000 + y];
            }
            d++;
        }
        d = 1;
        while (x - d >= 0 && y + d <= 1000)
        {
            if (m.count((x-d)*10000 + y+d) != 0 && m.count((x)*10000 + y+d) != 0 && m.count((x-d)*10000 + y) != 0)
            {
                ans += m[(x-d)*10000 + y+d] * m[(x)*10000 + y+d] * m[(x-d)*10000 + y];
            }
            d++;
        }
        d = 1;
        while (x - d >= 0 && y - d >= 0)
        {
            if (m.count((x-d)*10000 + y-d) != 0 && m.count((x)*10000 + y-d) != 0 && m.count((x-d)*10000 + y) != 0)
            {
                ans += m[(x-d)*10000 + y-d] * m[(x)*10000 + y-d] * m[(x-d)*10000 + y];
            }
            d++;
        }
        d = 1;
        while (x + d <= 1000 && y - d >= 0)
        {
            if (m.count((x+d)*10000 + y-d) != 0 && m.count((x)*10000 + y-d) != 0 && m.count((x+d)*10000 + y) != 0)
            {
                ans += m[(x+d)*10000 + y-d] * m[(x)*10000 + y-d] * m[(x+d)*10000 + y];
            }
            d++;
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */