class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> m;
        for (int i=0; i!=jewels.size(); i++)
        {
            m.insert(jewels[i]);
        }
        int ans=0;
        for (int i=0; i!=stones.size(); i++)
        {
            if (m.count(stones[i])!=0) ans++;
        }
        return ans;
    }
};