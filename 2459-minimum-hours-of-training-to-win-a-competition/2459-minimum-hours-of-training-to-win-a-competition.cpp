class Solution {
public:
    int minNumberOfHours(int en, int ex, vector<int>& arren, vector<int>& arrex) {
        int ans=0;
        for (int i=0; i!=arren.size(); i++)
        {
            ans=max(ans, arrex[i]-ex+1);
            en-=arren[i];
            ex+=arrex[i];
        }
        en--;
        if (en<0) ans-=en;
        return ans;
    }
};