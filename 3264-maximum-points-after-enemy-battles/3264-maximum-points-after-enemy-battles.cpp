class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long ans=0, en=currentEnergy;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if (enemyEnergies[0]>en) return 0;
        if (enemyEnergies.size()>1)
        {
            for (int i=1; i!=enemyEnergies.size(); i++) en+=enemyEnergies[i];
        }
        ans=en/enemyEnergies[0];
        return ans;
    }
};