class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int ans = f.size();
        for (int i=0; i!=f.size(); i++)
        {
            for (int j=0; j!=b.size(); j++)
            {
                if (b[j]>=f[i])
                {
                    b[j] = -1;
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};