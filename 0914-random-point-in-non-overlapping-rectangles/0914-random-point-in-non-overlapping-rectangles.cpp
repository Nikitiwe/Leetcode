class Solution {
private:
vector<vector<int>> r;
vector<long long> m;
long long s;

public:
    Solution(vector<vector<int>>& rects) {
        r = rects;
        s = 0;
        for (int i=0; i!=r.size(); i++)
        {
            m.push_back((long long)(r[i][2]-r[i][0]+1)*(r[i][3]-r[i][1]+1));
            s += m.back();
        }
    }
    
    vector<int> pick() {
        double a = (double)rand()/RAND_MAX;
        a *= s;
        long long b = 0;
        int i = 0;
        while (b < a)
        {
            b += m[i];
            i++;
        }
        i--;
        return {r[i][0] + rand()%(r[i][2] - r[i][0] + 1), r[i][1] + rand()%(r[i][3] - r[i][1] + 1)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */