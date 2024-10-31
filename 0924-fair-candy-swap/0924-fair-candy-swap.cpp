class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int suma=0, sumb=0;
        for (int i=0; i!=a.size(); i++) suma+=a[i];
        for (int i=0; i!=b.size(); i++) sumb+=b[i];
        int d=(sumb-suma)/2;
        unordered_set<int> m(b.begin(), b.end());
        for (int i=0; i!=a.size(); i++)
        {
            if (m.count(d+a[i])>0) return {a[i], d+a[i]};
        }
        return {-1, -1};
    }
};