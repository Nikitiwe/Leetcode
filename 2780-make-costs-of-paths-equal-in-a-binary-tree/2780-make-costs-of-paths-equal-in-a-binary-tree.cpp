class Solution {
public:
    int minIncrements(int n, vector<int>& nums) {
        vector<int> c = nums;
        int ma = 0;
        for (int i=0; i<c.size()/2; i++)
        {
            c[2*i + 1] += c[i];
            c[2*i + 2] += c[i];
            ma = max(ma, c[2*i + 1]);
            ma = max(ma, c[2*i + 2]);
        }
        vector<int> d(nums.size(), 0);
        for (int i=d.size()/2; i<d.size(); i++) d[i] = ma - c[i];
        int ans = 0;
        for (int i=d.size()/2-1; i>=0; i--)
        {
            int add = min(d[2*i + 1], d[2*i + 2]);
            d[2*i + 1] -= add;
            d[2*i + 2] -= add;
            d[i] += add;
        }
        for (int i=0; i!=d.size(); i++) ans += d[i];
        return ans;
    }
};