class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> delta(rocks.size(), 0);
        for (int i=0; i!=rocks.size(); i++)
        {
            delta[i]=capacity[i]-rocks[i];
        }
        sort(delta.begin(), delta.end());
        int ans=0, i=0;
        while (i<rocks.size())
        {
            if (additionalRocks>=delta[i])
            {
                additionalRocks-=delta[i];
                i++;
                ans++;
            }
            else break;
        }
        return ans;
    }
};