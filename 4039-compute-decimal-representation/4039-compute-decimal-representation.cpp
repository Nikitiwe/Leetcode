class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        while (n > 0)
        {
            long t = 1;
            while (t*10 <= n) t *= 10;
            long c = n/t;
            ans.push_back(c*t);
            n -= c*t;
        }
        return ans;
    }
};