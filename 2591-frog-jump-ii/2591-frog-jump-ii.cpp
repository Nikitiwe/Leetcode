class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans=0;
        if (stones.size()==2) return stones[1]-stones[0];

            for (int i=2; i<stones.size(); i=i+2)
            {
                ans=max(ans, stones[i]-stones[i-2]);
            }
            for (int i=3; i<stones.size(); i=i+2)
            {
                ans=max(ans, stones[i]-stones[i-2]);
            }

        return ans;
    }
};