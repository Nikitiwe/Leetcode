class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size(), 0);
        for (int i=0; i!=spells.size(); i++)
        {
            int l=0, r=potions.size()-1, m;
            while (l<r)
            {
                m=(l+r)/2;
                if ((long)potions[m]*spells[i]>=success) {r=m;}
                else {l=m+1;}
            }
            if (l>0&&(long)potions[l-1]*spells[i]>=success) l--;
            else if (l<potions.size()&&(long)potions[l]*spells[i]<success) l++;
            ans[i]=potions.size()-l;
        }
        return ans;
    }
};