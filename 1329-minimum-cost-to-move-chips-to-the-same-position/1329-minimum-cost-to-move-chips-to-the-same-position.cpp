class Solution {
public:
    int minCostToMoveChips(vector<int>& p) {
        int a=0, b=0;
        for (int i=0; i!=p.size(); i++)
        {
            if (p[i]%2==0) a++;
            else b++;
        }
        return min(a, b);
    }
};