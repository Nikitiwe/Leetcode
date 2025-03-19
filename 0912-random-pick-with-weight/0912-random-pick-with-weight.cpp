class Solution {
private:
    vector<int> id;
    int s;
public:
    Solution(vector<int>& w) {
        id = w;
        s = 0;
        for (int i=0; i!=id.size(); i++) s+=id[i];
    }
    
    int pickIndex() {
        double a = (double)rand()/RAND_MAX * s;
        int i = 0;
        int sum = 0;
        while (sum < a)
        {
            sum += id[i];
            i++;
        }
        i--;
        return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */