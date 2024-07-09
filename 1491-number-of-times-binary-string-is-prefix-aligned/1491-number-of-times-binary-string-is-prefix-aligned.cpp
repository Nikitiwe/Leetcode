class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int m=0, ans=0;
        for (int i=0; i!=flips.size(); i++)
        {
            m=max(m, flips[i]);
            if (m==i+1) ans++;
        }
        return ans;
    }
};