class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& d) {
        int id=0, ans=0;
        for (int i=0; i!=d.size(); i++)
        {
            int c=0;
            for (int j=0; j!=nums.size(); j++) if (nums[j]%d[i]==0) c++;
            if (c>ans)
            {
                id=i;
                ans=c;
            }
            else if (c==ans)
            {
                if (d[i]<d[id]) id=i;
            }
        }
        return d[id];
    }
};