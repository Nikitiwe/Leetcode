class Solution {
public:
    int numRescueBoats(vector<int>& p, int q) {
        sort(p.begin(), p.end());
        int l=0, r=p.size()-1, ans=0;
        while (l<=r)
        {
            if (l!=r)
            {
                if (p[l]+p[r]<=q)
                {
                    l++;
                    r--;
                    ans++;
                }
                else
                {
                    r--;
                    ans++;
                }
            }
            else
            {
                ans++;
                break;
            }
        }
        return ans;
    }
};