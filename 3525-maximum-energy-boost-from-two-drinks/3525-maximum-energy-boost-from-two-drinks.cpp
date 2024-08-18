class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        long long a=energyDrinkA[0], b=energyDrinkB[0], n=0, ta, tb, tn;
        for (int i=1; i!=energyDrinkA.size(); i++)
        {
            ta=a; tb=b; tn=n;
            n=max(ta, tb);
            a=max(ta, tn)+energyDrinkA[i];
            b=max(tb, tn)+energyDrinkB[i];
        }
        return max(a, b);
    }
};